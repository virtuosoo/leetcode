import java.util.concurrent.CountDownLatch;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;
import java.util.concurrent.Executors;

public class MultiThreadPrint {
    private static int state= 0 ;
    private static ReentrantLock lock = new ReentrantLock();
    private static Condition aCanWrite = lock.newCondition();
    private static Condition bCanWrite = lock.newCondition();
    private static Condition cCanWrite = lock.newCondition();
    public static void main(String[] args) throws InterruptedException {
        ExecutorService threadPool = Executors.newFixedThreadPool(3);
        CountDownLatch latch = new CountDownLatch(3);
        threadPool.execute(() -> {
            for (int i = 0; i < 10; ++i) {
                lock.lock();
                try {
                    while (state != 0) {
                        aCanWrite.await();
                    }
                    System.out.println("A");
                    state = (state + 1) % 3;
                    bCanWrite.signal();
                }catch(InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    lock.unlock();
                }
            }
            latch.countDown();
        });

        threadPool.execute(() -> {
            for (int i = 0; i < 10; ++i) {
                lock.lock();
                try {
                    while (state != 1) {
                        bCanWrite.await();
                    }
                    System.out.println("B");
                    state = (state + 1) % 3;
                    cCanWrite.signal();
                }catch(InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    lock.unlock();
                }
            }
            latch.countDown();
        });

        threadPool.execute(() -> {
            for (int i = 0; i < 10; ++i) {
                lock.lock();
                try {
                    while (state != 2) {
                        cCanWrite.await();
                    }
                    System.out.println("C");
                    state = (state + 1) % 3;
                    aCanWrite.signal();
                }catch(InterruptedException e) {
                    e.printStackTrace();
                } finally {
                    lock.unlock();
                }
            }
            latch.countDown();
        });
        latch.await();
        threadPool.shutdown();
    }
}
