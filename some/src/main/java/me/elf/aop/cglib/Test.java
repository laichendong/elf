package me.elf.aop.cglib;

import net.sf.cglib.proxy.Enhancer;

/**
 * @author laichendong
 * @since 14-6-10
 */
public class Test {
    public static void main(String[] args) {
        Enhancer enhancer = new Enhancer();
        enhancer.setSuperclass(TargetService.class);
        enhancer.setCallback(new TargetServiceInterceptor());
        TargetService targetService = (TargetService) enhancer.create();
        targetService.doSomething();
    }
}
