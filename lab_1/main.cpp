#include "string.hpp"
#include <iostream>

void demonstrateString() {
    std::cout << "=== Демонстрация работы класса String ===\n\n";
    
    // Конструкторы
    std::cout << "1. Конструкторы:\n";
    String s1; // по умолчанию
    String s2("Hello"); // от C-строки
    String s3(s2); // копирования
    
    std::cout << "   s2 = " << s2 << ", s3 = " << s3 << "\n\n";
    
    // Оператор присваивания
    std::cout << "2. Оператор присваивания:\n";
    s1 = s2;
    std::cout << "   s1 = s2 -> s1 = " << s1 << "\n\n";
    
    // Оператор []
    std::cout << "3. Оператор []:\n";
    std::cout << "   s2[0] = " << s2[0] << "\n";
    s2[0] = 'h';
    std::cout << "   s2[0] = 'h' -> s2 = " << s2 << "\n\n";
    
    // Size и Empty
    std::cout << "4. Size() и Empty():\n";
    std::cout << "   s2.Size() = " << s2.Size() << "\n";
    std::cout << "   s2.Empty() = " << (s2.Empty() ? "true" : "false") << "\n\n";
    
    // Конкатенация
    std::cout << "5. Конкатенация (+= и +):\n";
    String s4(" World");
    s2 += s4;
    std::cout << "   s2 += \" World\" -> s2 = " << s2 << "\n";
    String s5 = s2 + String("!");
    std::cout << "   s5 = s2 + \"!\" -> s5 = " << s5 << "\n\n";
    
    // Умножение
    std::cout << "6. Умножение (*= и *):\n";
    String s6("ABC");
    s6 *= 2;
    std::cout << "   s6 = \"ABC\" *= 2 -> s6 = " << s6 << "\n";
    String s7 = s6 * 2;
    std::cout << "   s7 = s6 * 2 -> s7 = " << s7 << "\n\n";
    
    // Сравнение
    std::cout << "7. Операторы сравнения:\n";
    String s8("abc");
    String s9("def");
    std::cout << "   s8 = " << s8 << ", s9 = " << s9 << "\n";
    std::cout << "   s8 == s9? " << (s8 == s9 ? "да" : "нет") << "\n";
    std::cout << "   s8 < s9? " << (s8 < s9 ? "да" : "нет") << "\n";
    std::cout << "   s8 > s9? " << (s8 > s9 ? "да" : "нет") << "\n\n";
    
    // Поиск подстроки
    std::cout << "8. Find():\n";
    String s10("Hello World");
    std::cout << "   s10 = " << s10 << "\n";
    std::cout << "   Find(\"World\") = " << s10.Find("World") << "\n";
    std::cout << "   Find(\"xyz\") = " << s10.Find("xyz") << "\n\n";
    
    // Замена символов
    std::cout << "9. Replace():\n";
    String s11("Hello World");
    s11.Replace('l', 'L');
    std::cout << "   s11 = \"Hello World\", Replace('l', 'L') -> " << s11 << "\n\n";
    
    // Обрезка
    std::cout << "10. Обрезка (LTrim и RTrim):\n";
    String s12("___Hello___");
    std::cout << "    s12 = " << s12 << "\n";
    s12.LTrim('_');
    std::cout << "    LTrim('_') -> " << s12 << "\n";
    s12.RTrim('_');
    std::cout << "    RTrim('_') -> " << s12 << "\n\n";
    
    // Swap
    std::cout << "11. swap():\n";
    String s13("first");
    String s14("second");
    std::cout << "    До swap: s13 = " << s13 << ", s14 = " << s14 << "\n";
    s13.swap(s14);
    std::cout << "    После swap: s13 = " << s13 << ", s14 = " << s14 << "\n\n";
    
    std::cout << "=== Демонстрация завершена ===\n";
}

int main() {
    demonstrateString();
    return 0;
}