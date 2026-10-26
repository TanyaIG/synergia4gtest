#pragma once

#include <optional>

template <typename T>
class IBinaryTree {
public:
    virtual ~IBinaryTree() = default;

    // Добавляет значение в бинарное дерево поиска.
    virtual void push(const T& value) = 0;

    // Удаляет и возвращает значение согласно контракту реализации.
    // Если дерево пустое -> std::nullopt.
    virtual std::optional<T> pop() = 0;

    // Возвращает true, если значение найдено.
    virtual bool search(const T& value) const = 0;
};
