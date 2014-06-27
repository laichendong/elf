package me.elf.aop.proxy;

/**
 * sevice实现类
 * @author laichendong
 * @since 14-6-10
 */
public class TagetServiceImpl implements TagetService {

    /**
     * 需要被拦截的方法
     */
    @Override
    public void doSomething() {
        System.out.println("doing something.");
    }
}
