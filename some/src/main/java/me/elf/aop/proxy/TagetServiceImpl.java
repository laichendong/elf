package me.elf.aop.proxy;

/**
 * seviceʵ����
 * @author laichendong
 * @since 14-6-10
 */
public class TagetServiceImpl implements TagetService {

    /**
     * ��Ҫ�����صķ���
     */
    @Override
    public void doSomething() {
        System.out.println("doing something.");
    }
}
