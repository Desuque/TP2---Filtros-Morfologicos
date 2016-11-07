
#ifndef THREAD_H_
#define THREAD_H_

#include <thread>

class Thread {
	private:
		std::thread thread;
    public:
        Thread();
        void start();
        void join();
        virtual void run() = 0;
        virtual ~Thread();

    private:
        Thread(const Thread&) = delete;
        Thread& operator=(const Thread&) = delete;
};

#endif /* THREAD_H_ */
