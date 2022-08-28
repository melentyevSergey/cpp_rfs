#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    /*
        ВКЛЮЧЕНИЕ ЗАГОЛОВОЧНОГО ФАЙЛА ОДИН РАЗ
    */
    #ifndef NAME_HPP
    #define NAME_HPP
    // header file
    #endif

    // the same as above
    #pragma once




    /*
        Размер типа
    */
    #include <cstdint>                                   // int8_t, uint8_t...
    cout << sizeof(int16_t) << endl;



    /*
        КЛЮЧЕВОЕ СЛОВО USING
    */
    using Document = pair<int, int>;
    using DocumentContent = pair<int, vector<string>>;
    vector<Document> FindTopDocuments(const vector<DocumentContent>& documents){}




    /*
        АЛГОРИТМЫ
    */

    // поиск по строке на исключение набора спецсимволов
    none_of(word.begin(), word.end(), [](char c) {
        return c >= '\0' && c < ' ';
    });



    /*
        ИТЕРАТОРЫ
    */

    // добавление элементов в контейнер
    vector<string> langs = {"Python"s, "Java"s, "C#"s, "Ruby"s, "C++"s};
    auto it_begin = begin(langs);                       // получить итератор на нулевой позиции
    auto it_begin = langs.begin();
    auto it_end = end(langs);                           // получить итератор на последней позиции
    auto it_end = langs.end();
    auto it = find(langs.begin(), langs.end(), "C++"s); // получить итератор на первый совпадающий эл

    langs.insert(langs.begin(), "C"s);                  // вставил "С" нулевым элементом
    langs.insert(langs.end(), "C"s);                    // вставил "С" последним элементом
    langs.insert(it, "C"s);                             // вставил "С" до "С++"
    langs.insert(it, range_begin, range_end);           // вставит полуинтервал
    langs.insert(it, n, value);                         // вставит "n" раз элемент value до "С++"
    langs.insert(it, {1, 2, 3});                        // вставит {1, 2, 3} до "С++"

    auto it_next = container.erase(it);                 // удалить элемент и получить след итератор

    // вывести содержание контейнера на печать
    template <typename It>
    void PrintRange(It range_begin, It range_end) {
        bool is_first = true;
        for (auto it = range_begin; it != range_end; ++it) {
            if (!is_first) {
                cout << " "s;
            }
            is_first = false;
            cout << *it;
        }
        cout << endl;
    }

    // найти нужный элемент в контейнере и применить действия до него и после
    template <typename Container, typename Element>
    void FindAndPrint(const Container& container, const Element& element_to_find) {
        auto it_begin = begin(container);
        auto it_end = end(container);
        auto it = find(it_begin, it_end, element_to_find);
        PrintRange(it_begin, it);   // действие с элементами от начала и до заданного элемента
        PrintRange(it, it_end);     // действие от заданного элемента и до конца
    }

    // удалить элемент из контейнера по номеру позиции и следом удалить интервал в контейнере
    template <typename Container>
    void EraseAndPrint(Container& container, int position_to_remove, int range_begin, int range_end) {
        container.erase(container.begin() + position_to_remove);
        container.erase(container.begin() + range_begin, container.begin() + range_end);
    }




    /*
        КЛАСС / CLASS
    */

    // Инициалиация полей класса
    class Widget {
        Widget() = default;
        explicit Widget(int j) : i {j} {...};

    private:
        int i {42};
        std::string s {"Cpp"};
        int* pi {};
    };

    // Метод с опциональным типом при возврате
    optional<vector<string>> MethodName(const string& raw_query) const {
        if (false) {
            return nullopt;
        }
    }




    /*
        СТРУКТУРА / STRUCT
    */
    // объявление в заголовочном файле
    struct Point {
        double x;
        double y;
        void shift (double x, double y);
    };

    // определение в .cpp файле
    void Point::shift(double x, double y) {
        this -> x += x;                           // указать на структуру передается в аргументе
        this -> y += y;
    }




    /*
        СЛОВАРЬ / MAP
    */
    map<string, int> mapNameFirst;
    const map<string, int> mapNameSecond
    mapNameFirst[keyName] <= mapNameSecond.at(keyName); // доступ по ключу

    map<int, string> mapName;                           // наполнить словарь значениями
    mapName.insert(make_pair(1, "Name"));




    /*
        ВЕКТОР / VECTOR
    */
    vector<int> ratings(ratings_size, 0);               // инициализировать вектор и наполнить
    for (int& rating : ratings) cin >> rating;
    
    int r = count(vName.begin(), vName.end(), 1);       // поиск по вхождениям
    int r = count_if(vName.begin(), vName.end(), [](int x){ return x > 0; });   // с условием

    sort(xs.begin(), xs.end());                         // сортировка по возрастанию
    ?revers(xs.begin(), xs.end());                        // сортировка по убыванию

    #include <numeric>
    int s = accumulate(vName.begin(), vName.end(), 0);  // аккумулятор значений, в т.ч. с условием
    int s = accumulate(vName.begin(), vName.end(), 1, [](int a, int b){ return a * b; });




    /*
        КОРТЕЖ / TUPLE
    */
    const tuple animal_info("Имя"s, 5, 4.1);
    cout << "Пациент "s << get<0>(animal_info);             // доступ по индексу
    cout << "Пациент "s << get<string>(animal_info)         // доступ по типу, если нет дублей
    
    class SearchServer {
        public:
            tuple<vector<string>, DocStatus> MethodName(const string& uery) const {};
    };
    const auto [words, status] = search_server.MethodName("строка"s);   // доступ через распаковку




    /*
        ФУНКЦИИ
    */
    // Шаблонные функции
    template <typename Term>
    map<Term, int> Compute(const vector<Term>& terms) {
        map<Term, int> term_freqs;
        for (const Term& term : terms) ++term_freqs[term];
        return term_freqs;
    } 

    // Обертка для sort
    template <typename Container, typename KeyMapper>
    void SortBy(Container& container, KeyMapper key_mapper) {
        sort(container.begin(), container.end(), [key_mapper](const auto& lhs, const auto& rhs) {
            return key_mapper(lhs) < key_mapper(rhs);
        });
    }
    SortBy(animals, [](const Animal& animal) { return -animal.weight; });




    /*
        ПЕРЕОПРЕДЕЛЕНИЕ ОПЕРАТОРА
    */
    template <typename Element>
    ostream& operator<<(ostream& out, const vector<Element>& container) {
        bool is_first = true;
        for (const auto& element : container) {
            if (!is_first) {
                out << ", "s;
            }
            is_first = false;
            out << element;
        }
        return out;
    }

    class ClassName {
    public:
        ClassName& operator+=(ClassName right) {
            // все бинарные операции
            return *this;
        }
    };




    /*
        Исключения
    */
    #include <stdexcept>

    throw invalid_argument("Не корректное значение аргумента"s);
    throw domain_error("Деление на ноль или нет общих точек пересечения"s);
    throw out_of_range("Получение индекса за пределами контейнера"s);
    throw runtime_error("Ошибки во время выполнения программы"s);
    throw bad_alloc("Ошибка выделения памяти"s);
    try {
        ...
    } catch (const domain_error& error) {
        cout << "Ошибка: "s << error.what() << endl;
    }




    /*
        UNIT TESTING
    */
    #include <cassert>

    const string& FindMinStr(const string& a, const string& b, const string& c) {...}
    void TestFindMinStr() {
        assert(FindMinStr("alpha"s, "beta"s, "gamma"s) == "alpha"s);
    }




    /*
        Замеры таймеров по операциям
    */
    auto begin = chrono::steady_clock::now();
    auto end = chrono::steady_clock::now();
    cout << "Time difference "s
         << chrono::duration_cast<chrono::microseconds>(end - begin).count()
         << "[µs]"s << endl;
}

