#pragma once

#include <optional>

template <typename T>
class IQueue {
public:
    virtual ~IQueue() = default;

    // Добавляет элемент в конец очереди.
    virtual void push(const T& value) = 0;

    // Извлекает и возвращает первый элемент; пустая очередь -> std::nullopt.
    virtual std::optional<T> pop() = 0;
};
