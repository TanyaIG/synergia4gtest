# Кейс-задача № 4 — GoogleTest

Учебный проект на C++ с интерфейсами очереди, кучи и бинарного дерева, а также unit-тестами на GoogleTest/GoogleMock.

> Реализация структур данных намеренно не предоставлена: задание требует только интерфейсы и тесты. Тесты используют mock-классы, поэтому проверяют ожидаемые вызовы интерфейсов без реализации алгоритмов.

## Требования
- CMake 3.20+
- C++17
- Git
- доступ к интернету при первой сборке (GoogleTest загружается через FetchContent)

## Сборка и запуск

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Публикация на GitHub

1. Создайте пустой репозиторий на https://github.com/new (например, `synergy-case4-gtest`).
2. В терминале перейдите в распакованную папку проекта и выполните:

```bash
git init
git add .
git commit -m "Add GoogleTest interface tests"
git branch -M main
git remote add origin https://github.com/ВАШ_ЛОГИН/synergy-case4-gtest.git
git push -u origin main
```

Замените `ВАШ_ЛОГИН` на свой логин GitHub. После публикации ссылка будет иметь вид:
`https://github.com/ВАШ_ЛОГИН/synergy-case4-gtest`
