package me.elf.consistent.hashing;

import org.apache.commons.codec.digest.DigestUtils;

import java.util.*;

/**
 * 一致性hash路由算法
 *
 * @author laichendong
 * @since 14-6-10
 */
public class ConsistentHashing<T> {

    /**
     * 节点集合
     */
    private Set<T> nodes = new HashSet<T>();

    /**
     * 节点环，用treeMap模拟实现
     */
    private TreeMap<Integer, T> ring = new TreeMap<Integer, T>();

    public ConsistentHashing() {
    }

    public ConsistentHashing(Set<T> nodes) {
        if (nodes == null) {
            throw new NullPointerException("nodes must not be null");
        }
        this.nodes = nodes;
        for (T node : nodes) {
            ring.put(hash(node), node);
        }
    }

    /**
     * 添加节点
     *
     * @param node 节点
     * @return 节点添加是否成功
     */
    public boolean addNode(T node) {
        ring.put(hash(node), node);
        return nodes.add(node);
    }

    /**
     * 移除节点
     *
     * @param node 节点
     * @return 节点移除是否成功
     */
    public boolean removeNode(T node) {
        ring.remove(hash(node));
        return nodes.remove(node);
    }

    /**
     * 计算路由
     *
     * @param key 需要计算路由的key
     * @return key落到的节点上
     */
    public T route(Object key) {
        int h = hash(key);
        // 找到离key最近的节点
        Map.Entry<Integer, T> entry = ring.floorEntry(h);
        if (entry == null) {
            // 如果没有找到，可能时到最前面了，返回最后一个节点，形成环
            entry = ring.lastEntry();
        }
        if (entry == null) {
            return null;
        } else {
            return entry.getValue();
        }
    }

    /**
     * 采用的hash算法
     * 这个可以根据需要进行修改
     *
     * @param key hash key
     * @return hash 值
     */
    public static int hash(Object key) {
        // 这个md5挺重要的，可以将相似的key的hash值打散，使节点在环上散布开来，当然，也可以使用其他方法
        int h = DigestUtils.md5Hex(key.toString()).hashCode();
        // 然后再copy了以下HashMap的hash算法～～
        h ^= (h >>> 20) ^ (h >>> 12);
        return h ^ (h >>> 7) ^ (h >>> 4);
    }

    /**
     * 测试
     */
    public static void main(String[] args) {
        // 初始化
        ConsistentHashing<String> consistentHashing = new ConsistentHashing<String>();
        consistentHashing.addNode("node0");
        consistentHashing.addNode("node1");
        consistentHashing.addNode("node2");
        consistentHashing.addNode("node3");

        // 对每一个key进行路由计算 看看分布情况
        String[] keys = {"key0", "key1", "key2", "key3", "key4", "key5", "key6", "key7"};
        for (String key : keys) {
            System.out.println(key + " -> " + consistentHashing.route(key));
        }
        System.out.println("=================");
        // 减掉一个节点，再对每一个key进行路由计算   看漂移结果
        consistentHashing.removeNode("node3");
        for (String key : keys) {
            System.out.println(key + " -> " + consistentHashing.route(key));
        }

    }

}
