package hotreplace;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class Main {
    public static void main(String[] args) throws InterruptedException, ClassNotFoundException,
            IllegalAccessException, InstantiationException, NoSuchMethodException, InvocationTargetException {
        while (true) {
            FileClassLoader fileClassLoader = new FileClassLoader();
            fileClassLoader.setFileName("SayHello.class");
            Object obj = null;
            obj = fileClassLoader.loadClass("hotreplace.SayHello").newInstance();
            Method m = obj.getClass().getMethod("say", new Class[]{});
            m.invoke(obj, new Object[]{});
            Thread.sleep(2000);
        }
    }
}
