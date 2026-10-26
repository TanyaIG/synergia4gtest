#pragma once

#include <optional>

template <typename T>
class IHeap {
public:
    virtual ~IHeap() = default;

    // Добавляет элемент в кучу.
    virtual void push(const T& value) = 0;

    // Извлекает элемент с наивысшим приоритетом согласно выбранному порядку.
    // Для max-heap это максимальный элемент; пустая куча -> std::nullopt.
    virtual std::optional<T> pop() = 0;
};
