package me.elf.aop.proxy;

import java.lang.reflect.Proxy;

/**
 * @author laichendong
 * @since 14-6-10
 */
public class Test {

    public static void main(String[] args) throws IllegalAccessException, InstantiationException {
        // service 实例
        TagetService instance = TagetServiceImpl.class.newInstance();
        // service 代理的实例
        TagetService tagetServiceProxy = (TagetService) Proxy.newProxyInstance(instance.getClass().getClassLoader(),
                instance.getClass().getInterfaces(),
                new TargetServiceInvocationHandler(instance));
        // 用代理的实例调用方法， 即会被handler拦截
        tagetServiceProxy.doSomething();
    }
}
