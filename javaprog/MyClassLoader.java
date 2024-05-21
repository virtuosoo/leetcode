import java.io.IOException;
import java.io.InputStream;

public class MyClassLoader extends ClassLoader {
 
    @Override
    public Class<?> loadClass(String name) throws ClassNotFoundException {
        if (name == null || "".equals(name)) {
            throw new ClassNotFoundException();
        }  
        else if (name.startsWith("java.")) {
            // �ɸ������java.��ͷ����
            return super.loadClass(name);
        }
        InputStream is = null;
        try {
            String className = "/" + name.replace('.', '/') + ".class";
            System.out.println("MyClassLoader:" + className);
            // ��classpath·���¼���java/lang/Object.class�ļ�
            is = getClass().getResourceAsStream(className);
            System.out.println(is);
            if (is == null) {
                throw new ClassNotFoundException();
            }
            byte[] bytes = new byte[is.available()];
            is.read(bytes);
            // ���ø���classLoader��defineClass����
            // ���ֽ�����ת��ΪClassʵ��
            return defineClass(name, bytes, 0, bytes.length);
        } catch (Exception e) {
            e.printStackTrace();
            throw new ClassNotFoundException();
        } finally {
            if (is != null) {
                try {
                    is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
 
    public static void main(String[] args) {
        MyClassLoader myClassLoader = new MyClassLoader();
        try {
            Class<?> clazz = Class.forName("myjava.lang.Object", true, myClassLoader);
            System.out.println("�Զ������������" + clazz.newInstance().getClass().getClassLoader());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}