package me.elf.aop.proxy;

import java.lang.reflect.Proxy;

/**
 * @author laichendong
 * @since 14-6-10
 */
public class Test {

    public static void main(String[] args) throws IllegalAccessException, InstantiationException {
        // service ʵ��
        TagetService instance = TagetServiceImpl.class.newInstance();
        // service �����ʵ��
        TagetService tagetServiceProxy = (TagetService) Proxy.newProxyInstance(instance.getClass().getClassLoader(),
                instance.getClass().getInterfaces(),
                new TargetServiceInvocationHandler(instance));
        // �ô����ʵ�����÷����� ���ᱻhandler����
        tagetServiceProxy.doSomething();
    }
}
