#include <iostream>
#include <queue>
#include <vector>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

using Client = size_t;

std::queue<Client> clients;
std::mutex mutex;

class Barber
{
public:
    void Work();
    void Push(Client client);
    void Trim(Client client);
private:
    size_t capacity_ = 3;
    std::condition_variable busy_;
};

void
Barber::Work()
{
    while (true)
    {
        Client client = -1;
        {
            std::unique_lock<std::mutex> lock(mutex);
            if (clients.empty())
            {
                std::cout << "Barber is sleeping..." << std::endl;
                busy_.wait(lock);
                std::cout << "Barber is awaking..." << std::endl;
            }

            client = clients.front();
            clients.pop();
        }
        Trim(client);
    }
}

void
Barber::Trim(Client client)
{
    auto seconds = rand() % 3;
    std::cout << "Barber is starting trim client #" << client << " for " << seconds << " seconds" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << "Barber finished to trim client #" << client << std::endl;
}

void
Barber::Push(Client client)
{
    std::unique_lock<std::mutex> lock(mutex);
    if (clients.size() >= capacity_)
    {
        std::cout << "There is no free places for client #" << client << "... [capacity:" << capacity_ << "]" << std::endl;
        return;
    }

    std::cout << "client #" << client << " is in queue" << std::endl;
    clients.push(client);
    busy_.notify_all();
}

int main()
{
    Barber barber;
    std::thread barber_thread([](Barber& barber){ barber.Work(); }, std::ref(barber));
    std::vector<std::thread> clients_threads;

    for (size_t i = 0; i < 20; ++i)
    {
        clients_threads.emplace_back([&i](Barber& barber) { barber.Push(i); }, std::ref(barber));
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    for (auto& thread : clients_threads)
    {
        thread.join();
    }
    barber_thread.join();
}
