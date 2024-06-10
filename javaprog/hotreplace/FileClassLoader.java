package hotreplace;

import java.io.File;
import java.io.IOException;
import java.io.InputStream;

public class FileClassLoader extends ClassLoader {
    private String fileName;

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public Class loadClass(String name) throws ClassNotFoundException {
        if (name.startsWith("java")) {
            return getSystemClassLoader().loadClass(name);
        }
        Class cls = null;
        File file = new File(fileName);
        InputStream is = getClass().getResourceAsStream(fileName);

        try {
            cls = instantiateClass(name, is, is.available());
        } catch (IOException e) {
        }
        return cls;
    }

    private Class instantiateClass(String name, InputStream fin, long len) throws IOException {
        byte[] raw = new byte[(int) len];
        fin.read(raw);
        fin.close();
        return defineClass(name, raw, 0, raw.length);
    }
}
