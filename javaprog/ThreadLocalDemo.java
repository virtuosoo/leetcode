public class ThreadLocalDemo {

    public static ThreadLocal<String> threadLocal =  new ThreadLocal<String>();
 
     public static void main(String[] args) {
         ThreadLocalDemo.threadLocal.set("hello world main");
         System.out.println("创建新线程前，主线程" + Thread.currentThread().getName() + "的threadlocal字符值为："  + ThreadLocalDemo.threadLocal.get());
 
         try {
             Thread thread = new Thread() {
                 @Override
                 public void run() {
                     ThreadLocalDemo.threadLocal.set("new thread");
                     System.out.println("新线程" + Thread.currentThread().getName() + "的threadlocal字符值为：" + ThreadLocalDemo.threadLocal.get());
                 }
             };
             thread.start();
             thread.join();
         } catch (Exception e) {
             System.out.println(e);
         }
         System.out.println("创建新线程后，主线程" + Thread.currentThread().getName() + "的threadlocal字符值为："  + ThreadLocalDemo.threadLocal.get());
 
     }
 }