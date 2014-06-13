package me.elf.aop.cglib;

import net.sf.cglib.proxy.MethodInterceptor;
import net.sf.cglib.proxy.MethodProxy;

import java.lang.reflect.Method;

/**
 * @author laichendong
 * @since 14-6-10
 */
public class TargetServiceInterceptor implements MethodInterceptor {
    @Override
    public Object intercept(Object obj, Method method, Object[] args, MethodProxy proxy) throws Throwable {
        System.out.println("before do something.");
        Object result = proxy.invokeSuper(obj, args);
        System.out.println("after do something.");
        return result;
    }
}
