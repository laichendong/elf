package me.elf.aop.proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

/**
 * @author laichendong
 * @since 14-6-10
 */
public class TargetServiceInvocationHandler implements InvocationHandler {
    /**
     * �����Ŀ�����
     */
    private Object target;

    public TargetServiceInvocationHandler(Object target) {
        this.target = target;
    }

    /**
     * ���ط�������
     *
     * @param proxy  ����
     * @param method ����
     * @param args   ����
     * @return
     * @throws Throwable
     */
    @Override
    public Object invoke(Object proxy, Method method, Object[] args) throws Throwable {
        System.out.println("before do something.");
        Object result = method.invoke(target, args);
        System.out.println("after do something.");
        return result;
    }
}
