package me.elf.aop.proxy;

import java.lang.reflect.InvocationHandler;
import java.lang.reflect.Method;

/**
 * @author laichendong
 * @since 14-6-10
 */
public class TargetServiceInvocationHandler implements InvocationHandler {
    /**
     * 代理的目标对象
     */
    private Object target;

    public TargetServiceInvocationHandler(Object target) {
        this.target = target;
    }

    /**
     * 拦截方法调用
     *
     * @param proxy  代理
     * @param method 方法
     * @param args   参数
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
