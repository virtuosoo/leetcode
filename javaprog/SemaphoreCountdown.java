import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Semaphore;

public class SemaphoreCountdown {
private static final int THREAD_NUM = 300;
    public static void main(String[] args) throws InterruptedException {
        ExecutorService threadPool = Executors.newFixedThreadPool(100);
        Semaphore sema =  new Semaphore(0);
        for (int i = 0; i < THREAD_NUM; ++i) {
            int num = i;
            threadPool.execute(() -> {
                try {
                    test(num);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    sema.release();
                }
            });
        }
        for (int i = 0; i < THREAD_NUM; ++i) {
            sema.acquire();
        }
        threadPool.shutdown();
        System.out.println("finish");
    }

    public static void test(int threadnum) throws InterruptedException {
        Thread.sleep(1000);
        System.out.println("threadNum:" + threadnum);
        Thread.sleep(1000);
    }
}
