package me.elf.consistent.hashing;

import org.apache.commons.codec.digest.DigestUtils;

import java.util.*;

/**
 * һ����hash·���㷨
 *
 * @author laichendong
 * @since 14-6-10
 */
public class ConsistentHashing<T> {

    /**
     * �ڵ㼯��
     */
    private Set<T> nodes = new HashSet<T>();

    /**
     * �ڵ㻷����treeMapģ��ʵ��
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
     * ��ӽڵ�
     *
     * @param node �ڵ�
     * @return �ڵ�����Ƿ�ɹ�
     */
    public boolean addNode(T node) {
        ring.put(hash(node), node);
        return nodes.add(node);
    }

    /**
     * �Ƴ��ڵ�
     *
     * @param node �ڵ�
     * @return �ڵ��Ƴ��Ƿ�ɹ�
     */
    public boolean removeNode(T node) {
        ring.remove(hash(node));
        return nodes.remove(node);
    }

    /**
     * ����·��
     *
     * @param key ��Ҫ����·�ɵ�key
     * @return key�䵽�Ľڵ���
     */
    public T route(Object key) {
        int h = hash(key);
        // �ҵ���key����Ľڵ�
        Map.Entry<Integer, T> entry = ring.floorEntry(h);
        if (entry == null) {
            // ���û���ҵ�������ʱ����ǰ���ˣ��������һ���ڵ㣬�γɻ�
            entry = ring.lastEntry();
        }
        if (entry == null) {
            return null;
        } else {
            return entry.getValue();
        }
    }

    /**
     * ���õ�hash�㷨
     * ������Ը�����Ҫ�����޸�
     *
     * @param key hash key
     * @return hash ֵ
     */
    public static int hash(Object key) {
        // ���md5ͦ��Ҫ�ģ����Խ����Ƶ�key��hashֵ��ɢ��ʹ�ڵ��ڻ���ɢ����������Ȼ��Ҳ����ʹ����������
        int h = DigestUtils.md5Hex(key.toString()).hashCode();
        // Ȼ����copy������HashMap��hash�㷨����
        h ^= (h >>> 20) ^ (h >>> 12);
        return h ^ (h >>> 7) ^ (h >>> 4);
    }

    /**
     * ����
     */
    public static void main(String[] args) {
        // ��ʼ��
        ConsistentHashing<String> consistentHashing = new ConsistentHashing<String>();
        consistentHashing.addNode("node0");
        consistentHashing.addNode("node1");
        consistentHashing.addNode("node2");
        consistentHashing.addNode("node3");

        // ��ÿһ��key����·�ɼ��� �����ֲ����
        String[] keys = {"key0", "key1", "key2", "key3", "key4", "key5", "key6", "key7"};
        for (String key : keys) {
            System.out.println(key + " -> " + consistentHashing.route(key));
        }
        System.out.println("=================");
        // ����һ���ڵ㣬�ٶ�ÿһ��key����·�ɼ���   ��Ư�ƽ��
        consistentHashing.removeNode("node3");
        for (String key : keys) {
            System.out.println(key + " -> " + consistentHashing.route(key));
        }

    }

}
