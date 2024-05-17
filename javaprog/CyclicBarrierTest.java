import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.CyclicBarrier;
import java.util.concurrent.BrokenBarrierException;

public class CyclicBarrierTest {

    public static void main(String[] args) {
        ExecutorService service = Executors.newCachedThreadPool();
        CyclicBarrier barrier = new CyclicBarrier(5, new Runnable() {
            @Override
            public void run() {
                System.out.println("全部到达"+Thread.currentThread().getName()+"呼叫服务员开始点餐！");
                service.shutdown();

            }
        });
        for (int j = 0; j < 5; j++) {
            service.execute(new Runnable() {
                @Override
                public void run() {
                    try {
                        Thread.sleep(1000);
                        System.out.println(Thread.currentThread().getName() + "同学到达");
                        barrier.await();
                        System.out.println(Thread.currentThread().getName()+"同学点餐");
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    } catch (BrokenBarrierException e) {
                        e.printStackTrace();
                    }
                }

            });
        }
        service.shutdown();
    }
}
