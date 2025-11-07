<div align="center">

# Vigenere Cipher Hacker / Взлом шифра Виженера

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=Lobster+Two&size=50&duration=6000&pause=1000&color=3B9600&center=true&vCenter=true&repeat=false&width=700&height=110&lines=%F0%9F%94%90+Vigen%C3%A8re+Cipher+Hacker+%F0%9F%94%90" alt="Vigenere Cipher Hacker - Cryptanalysis Tool" /></a>

![C++](https://img.shields.io/badge/C++-8A2BE2?style=for-the-badge&logo=c%2B%2B&logoColor=white&labelColor=6A0DAD&color=9B30FF)
![Cryptography](https://img.shields.io/badge/Cryptography-000000?style=for-the-badge&logo=key&logoColor=white)
[![C.C.](https://img.shields.io/badge/-C.C.-3B9600?style=for-the-badge&logo=star&logoColor=white&labelColor=0d1117)](https://github.com/C-C-C0de)

`vigenere-cipher-hacker` `cryptanalysis` `frequency-analysis` `classical-crypto` `security-tools` `cpp17` `algorithms`

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

![](https://github.com/C-C-C0de/C-C-C0de/blob/main/assets/Hacking-Vigener.gif?raw=true)

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg">
  <img src="https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=50&duration=4000&pause=1000&color=3B9600&center=true&vCenter=true&width=1000&height=100&lines=%F0%9F%8F%97%EF%B8%8F+%D0%A6%D0%95%D0%9B%D0%AC+%D0%9F%D0%A0%D0%9E%D0%95%D0%9A%D0%A2%D0%90+%F0%9F%8F%97%EF%B8%8F" alt="Typing SVG" />
</a>

</div>
 
 ____

&emsp;&emsp;Объяснить и реализовать полный алгоритм взлома шифра Виженера, предоставив пользователю:

> **1. Теоретическую основу** — вводная информация, как сам алгоритм рабоатет (методов Казиски и частотного анализа);

```cpp
Для более подробной информации обращайтесь к источникам. Моя задача ввести в дело и показать код. 
```

> **2. Практическую реализацию** — рабочий инструмент для криптоанализа; 

> **3. Интеллектуальную фильтрацию** — автоматический отбор наиболее осмысленных результатов.

<div align="center">

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=Momo+Trust+Display&size=60&duration=6000&pause=1000&color=3B9600&center=true&vCenter=true&width=1000&height=110&lines=%F0%9F%8C%8D+%D0%9E%D0%9F%D0%98%D0%A1%D0%90%D0%9D%D0%98%D0%95+%F0%9F%8C%8D" alt="Typing SVG" /></a>



____

</div>

> &emsp;&emsp;***Шифр Виженера*** — это полиалфавитный метод шифрования, предназначенный для защиты текстовых данных. Алгоритм был создан Блезом де Виженером в XVI веке и представляет собой усложнённую модификацию шифра Цезаря. Ключевым преимуществом метода является применение произвольного ключа в виде слова или фразы, что значительно повышает надёжность шифрования по сравнению с моноалфавитными системами.

&emsp;&emsp;Принцип действия основан на использовании ключевого слова, которое циклически повторяется вдоль всего текста. Каждая буква исходного сообщения сдвигается на величину, определяемую соответствующей буквой ключа, что обеспечивает полиалфавитность подстановки и устойчивость к частотному анализу.
____
> &emsp;&emsp;***Взлом шифра Виженера*** — это процесс криптоаналитического вскрытия полиалфавитного шифра без знания ключа, основанный на выявлении статистических закономерностей в зашифрованном тексте и определении длины ключевого слова с последующим восстановлением исходного сообщения.

> &emsp;&emsp;Для проверки работы кода, в стенде есть txt файл (``` Несколько примеров.txt ```) с примерами зашифрованого текста и ключа.


<div align="center">

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=Momo+Trust+Display&size=60&duration=6000&pause=1000&color=3B9600&center=true&vCenter=true&width=1000&height=110&lines=%F0%9F%8F%97%EF%B8%8F+%D0%90%D0%A0%D0%A5%D0%98%D0%A2%D0%95%D0%9A%D0%A2%D0%A3%D0%A0%D0%90+%D0%9A%D0%9E%D0%94%D0%90+%F0%9F%8F%97%EF%B8%8F" alt="Typing SVG" /></a>

</div>

<div align="center">

## 📦 ОСНОВНЫЕ МОДУЛИ СИСТЕМЫ

</div>

&emsp;&emsp;Программа представляет собой комплексную систему для взлома шифра Виженера, состоящую из нескольких взаимосвязанных модулей:

> ### 1. 🧠 НЕЙРОСЕТЬ TEXT TYPE PERCEPTRON

&emsp;&emsp;Многослойный перцептрон для анализа лингвистических особенностей текста. Класс включает:

&emsp;&emsp;**• Весовые коэффициенты** - 10 параметров для анализа различных лингвистических признаков;

&emsp;&emsp;**• Функции активации** - сигмоида и ее производная для обучения;

&emsp;&emsp;**• Извлечение признаков** - анализ триграмм, частотности букв, соотношения гласных/согласных;

&emsp;&emsp;**• Механизм обучения** - метод обратного распространения ошибки с обновлением весов.

> ### 2. 🔍 КРИПТОАНАЛИТИЧЕСКИЕ ФУНКЦИИ

&emsp;&emsp;Набор функций для реализации методов криптоанализа:

&emsp;&emsp;**• Метод Казиски** - поиск повторяющихся последовательностей для определения длины ключа;

&emsp;&emsp;**• Частотный анализ** - статистический анализ распределения символов;

&emsp;&emsp;**• Дешифрование** - обратное преобразование Виженера с найденным ключом;

&emsp;&emsp;**• Автоопределение языка** - распознавание русского и английского текстов.

<div align="center">

## 🌐 ПОДДЕРЖИВАЕМЫЕ ВОЗМОЖНОСТИ

</div>

&emsp;&emsp;**Языки:**  
&emsp;&emsp;&emsp;&emsp;• Русский (с учетом букв Ё/Е и различных порядков алфавита);

&emsp;&emsp;&emsp;&emsp;• Английский (стандартный латинский алфавит).

&emsp;&emsp;**Методы криптоанализа:**  
&emsp;&emsp;&emsp;&emsp;• Автоматическое определение длины ключа (2-20 символов);

&emsp;&emsp;&emsp;&emsp;• Частотный анализ с учетом языковых особенностей;

&emsp;&emsp;&emsp;&emsp;• Интеллектуальная оценка результатов через нейросеть;

&emsp;&emsp;&emsp;&emsp;• Ранжирование вариантов по вероятности осмысленности.

&emsp;&emsp;**Особенности реализации:**  
&emsp;&emsp;&emsp;&emsp;• Обучение нейросети на размеченных датасетах;

&emsp;&emsp;&emsp;&emsp;• Поддержка различных алфавитных последовательностей;

&emsp;&emsp;&emsp;&emsp;• Визуализация процесса анализа в реальном времени;

&emsp;&emsp;&emsp;&emsp;• Интерактивный интерфейс для работы с пользователем.

<div align="center">

## 🔄 ПРОЦЕСС РАБОТЫ

</div>

**1. Инициализация** - загрузка и обучение нейросети на примерах текстов;

**2. Ввод данных** - получение зашифрованного текста от пользователя;

**3. Анализ** - последовательное применение методов Казиски и частотного анализа;

**4. Оценка** - классификация результатов с помощью нейросети;

**5. Вывод** - представление лучших вариантов расшифровки с ранжированием.

<div align="center">

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=Momo+Trust+Display&size=60&duration=6000&pause=1000&color=3B9600&center=true&vCenter=true&width=1000&height=110&lines=%F0%9F%94%8D+%D0%9F%D0%A0%D0%98%D0%9D%D0%A6%D0%98%D0%9F+%D0%A0%D0%90%D0%91%D0%9E%D0%A2%D0%AB+%D0%92%D0%97%D0%9B%D0%9E%D0%9C%D0%90+%F0%9F%94%8D" alt="Typing SVG" /></a>

## 🛠️ Схема взлома шифра Виженера 🛠️

</div>

| Этап | Блок | Метод | Описание | Результат |
|------|------|-------|----------|-----------|
| **1** | **Определение длины ключа** | Метод Казиски | Поиск повторяющихся последовательностей (3-5 символов) и вычисление НОД расстояний между ними | Длина ключа |
| **2** | **Разделение на группы** | Распределение символов | Создание N групп (где N - длина ключа) и распределение символов: i-й символ → группа[i % N] | Группы символов |
| **3** | **Частотный анализ** | Статистический анализ | Для каждой группы: подсчет частот, нахождение самого частого символа, сравнение с 'E'/'О' для определения сдвига | Буквы ключа |
| **4** | **Восстановление ключа** | Объединение результатов | Комбинирование найденных букв из всех групп в полный ключ | Ключ шифрования |
| **5** | **Дешифрование** | Обратное преобразование | Применение обратного шифра Виженера с найденным ключом | Расшифрованный текст |
| **6** | **🧠 Оценка нейросетью** | **Нейронная сеть** | **Анализ осмысленности текста через перцептрон, обученный на триграммах и частотности букв** | **Вероятность осмысленности** |

<div align="center">

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=Momo+Trust+Display&size=45&duration=6000&pause=1000&color=3B9600&center=true&vCenter=true&width=1000&height=80&lines=%F0%9F%A7%A0+%D0%9D%D0%95%D0%99%D0%A0%D0%9E%D0%A1%D0%95%D0%A2%D0%AC+%D0%92+%D0%9A%D0%A0%D0%98%D0%9F%D0%A2%D0%9E%D0%90%D0%9D%D0%90%D0%9B%D0%98%D0%97%D0%95+%F0%9F%A7%A0" alt="Typing SVG" /></a>

## 🧠 Инновационный подход: интеграция нейросети

</div>

### 🤔 **Проблема традиционных методов**
&emsp;&emsp;&emsp;&emsp;Классический взлом шифра Виженера часто дает **несколько возможных вариантов** расшифровки. Без автоматической оценки качества результатов пользователю приходится **вручную анализировать** каждый вариант на осмысленность.

### 💡 **Решение: нейросеть-классификатор**
&emsp;&emsp;&emsp;&emsp;Было реализовано **интеллектуальное решение** - многослойный перцептрон, который анализирует расшифрованные тексты и определяет их осмысленность:

```cpp
class TextTypePerceptron {
    // Анализ лингвистических особенностей:
    // • Частотность триграмм ("СТО", "ЕНИ", "THE", "AND")
    // • Распределение букв ('О', 'Е', 'А', 'E', 'T', 'A')  
    // • Соотношение гласных/согласных
    // • Редкие буквы ('Ф', 'Щ', 'Z', 'Q')
};
```

> P.s. На этом все!!! Остальное мне лень рассписывать. Дальше сами...

<div align="center">

![](https://media1.tenor.com/m/ThULTnx4eUgAAAAd/squirrel-spinning-around.gif)

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=EB+Garamond&size=90&duration=6000&pause=1000&color=3B9600&center=true&vCenter=true&width=1000&height=110&lines=-+%D0%90%D0%92%D0%A2%D0%9E%D0%A0+-+" alt="Typing SVG" /></a>

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=Sixtyfour&size=70&duration=6000&pause=1000&color=000000&background=07BD1B&center=true&vCenter=true&repeat=false&width=1000&height=110&lines=%E2%94%81%E2%94%81%E2%94%81%E2%94%81%E2%9C%A6+C.C.+%E2%9C%A6%E2%94%81%E2%94%81%E2%94%81%E2%94%81;%E2%95%90%E2%95%90%E2%95%90%E2%95%90%E2%99%A6+C.C.+%E2%99%A6%E2%95%90%E2%95%90%E2%95%90%E2%95%90;%E2%94%85%E2%94%85%E2%94%85%E2%9C%A7+C.C.+%E2%9C%A7%E2%94%85%E2%94%85%E2%94%85;%E2%95%8D%E2%95%8D%E2%95%8D%E2%99%A0+C.C.+%E2%99%A0%E2%95%8D%E2%95%8D%E2%95%8D;%E3%80%9C%E3%80%9C%E3%80%9C%E2%8C%AC+C.C.+%E2%8C%AC%E3%80%9C%E3%80%9C%E3%80%9C;%E2%9C%A6%E2%9C%A6+C.C.+%E2%9C%A6%E2%9C%A6;%E2%9A%A1%E2%9A%A1+C.C.+%E2%9A%A1%E2%9A%A1;%F0%9F%8E%AE%F0%9F%8E%AE+C.C.+%F0%9F%8E%AE%F0%9F%8E%AE" alt="Typing SVG" /></a>

[![C.C.](https://img.shields.io/badge/-C.C.-3B9600?style=for-the-badge&logo=star&logoColor=white&labelColor=0d1117)](https://github.com/C-C-C0de)

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

<a href="https://git.io/typing-svg"><img src="https://readme-typing-svg.demolab.com?font=EB+Garamond&size=90&duration=6000&pause=1000&color=3B9600&center=true&vCenter=true&width=1000&height=110&lines=%D0%9A%D0%9E%D0%94+%D0%A1%2B%2B" alt="Typing SVG" /></a>

![Views](https://visitor-badge.laobi.icu/badge?page_id=C-C-C0de.Vigener-encryption)

</div>

```Cpp
#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <algorithm>
#include <cmath>

using namespace std;

class TextTypePerceptron {
private:
    double weights[10];
    double bias;
    double learning_rate;

public:
    TextTypePerceptron() {
        learning_rate = 0.1;
        bias = 0.0;
        for (int i = 0; i < 10; i++) {
            weights[i] = 0.5;
        }
    }

    double sigmoid(double x) {
        return 1.0 / (1.0 + exp(-x));
    }

    double sigmoid_derivative(double x) {
        return x * (1 - x);
    }

    double letterFrequency(const string& text, char letter) {
        int count = 0;
        for (int i = 0; i < text.length(); i++) {
            if (toupper(text[i]) == toupper(letter)) count++;
        }
        return text.length() > 0 ? (double)count / text.length() : 0;
    }

    double trigramFrequency(const string& text, const string& trigram) {
        int count = 0;
        for (int i = 0; i < (int)text.length() - 2; i++) {
            if (toupper(text[i]) == toupper(trigram[0]) &&
                toupper(text[i + 1]) == toupper(trigram[1]) &&
                toupper(text[i + 2]) == toupper(trigram[2])) {
                count++;
            }
        }
        return text.length() > 2 ? (double)count / (text.length() - 2) : 0;
    }

    double vowelRatio(const string& text, const string& language) {
        int vowels = 0;
        string vowelLetters;

        if (language == "russian") {
            vowelLetters = "АЕЁИОУЫЭЮЯаеёиоуыэюя";
        }
        else {
            vowelLetters = "AEIOUaeiou";
        }

        for (int i = 0; i < text.length(); i++) {
            if (vowelLetters.find(text[i]) != string::npos) vowels++;
        }
        return text.length() > 0 ? (double)vowels / text.length() : 0;
    }

    void extractFeatures(const string& text, double features[10], const string& language) {
        if (language == "russian") {
            features[0] = trigramFrequency(text, "СТО");
            features[1] = trigramFrequency(text, "ЕНИ");
            features[2] = trigramFrequency(text, "ОВА");

            features[3] = letterFrequency(text, 'О');
            features[4] = letterFrequency(text, 'Е');
            features[5] = letterFrequency(text, 'А');

            features[6] = vowelRatio(text, "russian");

            features[7] = letterFrequency(text, 'Ф');
            features[8] = letterFrequency(text, 'Щ');
            features[9] = letterFrequency(text, 'Э');
        }
        else {
            features[0] = trigramFrequency(text, "THE");
            features[1] = trigramFrequency(text, "AND");
            features[2] = trigramFrequency(text, "ING");

            features[3] = letterFrequency(text, 'E');
            features[4] = letterFrequency(text, 'T');
            features[5] = letterFrequency(text, 'A');

            features[6] = vowelRatio(text, "english");

            features[7] = letterFrequency(text, 'Z');
            features[8] = letterFrequency(text, 'Q');
            features[9] = letterFrequency(text, 'X');
        }
    }

    double predict(const string& text, const string& language) {
        double features[10];
        extractFeatures(text, features, language);

        double sum = bias;
        for (int i = 0; i < 10; i++) {
            sum += weights[i] * features[i];
        }

        return sigmoid(sum);
    }

    void trainExample(const string& text, double target, const string& language) {
        double features[10];
        extractFeatures(text, features, language);

        double prediction = predict(text, language);
        double error = target - prediction;
        double delta = error * sigmoid_derivative(prediction);

        for (int i = 0; i < 10; i++) {
            weights[i] += learning_rate * delta * features[i];
        }
        bias += learning_rate * delta;
    }

    void train(const string training_texts[10], double targets[10], int epochs, const string& language) {
        cout << "Начинаем обучение для " << (language == "russian" ? "русского" : "английского") << " языка..." << endl;

        for (int epoch = 0; epoch < epochs; epoch++) {
            double total_error = 0;

            for (int i = 0; i < 10; i++) {
                double prediction = predict(training_texts[i], language);
                double error = targets[i] - prediction;
                total_error += error * error;
                trainExample(training_texts[i], targets[i], language);
            }

            if (epoch % 1000 == 0) {
                cout << "Эпоха " << epoch << ", Ошибка: " << total_error << endl;
            }
        }
        cout << "Обучение завершено!" << endl;
    }

    string getTextType(double probability) {
        if (probability > 0.7) return "ОСМЫСЛЕННЫЙ ТЕКСТ";
        else if (probability > 0.4) return "ЧАСТИЧНО ОСМЫСЛЕННЫЙ ТЕКСТ";
        else return "СЛУЧАЙНЫЙ ТЕКСТ ИЛИ ШУМ";
    }
};

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int findGCD(int distances[], int count) {
    if (count == 0) return 0;
    int result = distances[0];
    for (int i = 1; i < count; i++) {
        result = gcd(result, distances[i]);
        if (result == 1) break;
    }
    return result;
}

bool isRussianLetter(char c) {
    return (c >= 'А' && c <= 'Я') || (c >= 'а' && c <= 'я') || c == 'Ё' || c == 'ё';
}

bool isEnglishLetter(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

char toUpperRussian(char c) {
    if (c >= 'а' && c <= 'я') return c - 32;
    if (c == 'ё') return 'Ё';
    return c;
}

char toUpperEnglish(char c) {
    if (c >= 'a' && c <= 'z') return c - 32;
    return c;
}

string detectLanguage(const string& text) {
    int russianCount = 0;
    int englishCount = 0;

    for (char c : text) {
        if (isRussianLetter(c)) russianCount++;
        else if (isEnglishLetter(c)) englishCount++;
    }

    if (russianCount > englishCount) return "russian";
    if (englishCount > russianCount) return "english";
    return "unknown";
}

string prepareText(const string& text, const string& language) {
    string result;
    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        if (language == "russian" && isRussianLetter(c)) {
            result += toUpperRussian(c);
        }
        else if (language == "english" && isEnglishLetter(c)) {
            result += toUpperEnglish(c);
        }
    }
    return result;
}

void getPossibleAlphabets(const string& language, string alphabets[4], int& alphabetCount) {
    alphabetCount = 0;

    if (language == "russian") {
        alphabets[alphabetCount++] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        alphabets[alphabetCount++] = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
        alphabets[alphabetCount++] = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";
        alphabets[alphabetCount++] = "АБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЬЫЪЭЮЯ";
    }
    else {
        alphabets[alphabetCount++] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        alphabetCount = 1;
    }
}

void findDivisors(int n, int divisors[], int& divisorCount) {
    divisorCount = 0;
    for (int i = 1; i <= n && i <= 20; i++) {
        if (n % i == 0) {
            divisors[divisorCount++] = i;
        }
    }
}

char frequencyAnalysisWithAlphabet(const string& group, const string& alphabet, const string& language) {
    int n = alphabet.length();
    int freq[50] = { 0 };
    for (char c : group) {
        size_t pos = alphabet.find(c);
        if (pos != string::npos && pos < 50) {
            freq[pos]++;
        }
    }
    int maxFreq = 0;
    int mostFrequentIndex = 0;

    for (int i = 0; i < n && i < 50; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequentIndex = i;
        }
    }

    char referenceChar;
    if (language == "russian") {
        referenceChar = 'О';
    }
    else {
        string commonLetters = "ETAOINSHRDLCUMWFGYPBVKJXQZ";
        int bestScore = -1;
        char bestChar = 'E';

        for (char commonChar : commonLetters) {
            int commonIndex = alphabet.find(commonChar);
            if (commonIndex == string::npos) continue;

            int shift = (mostFrequentIndex - commonIndex + n) % n;

            int score = 0;
            for (int i = 0; i < n && i < 50; i++) {
                if (freq[i] > 0) {
                    char decryptedChar = alphabet[(i - shift + n) % n];
                    if (decryptedChar == 'E' || decryptedChar == 'T' || decryptedChar == 'A' ||
                        decryptedChar == 'O' || decryptedChar == 'I' || decryptedChar == 'N') {
                        score += freq[i] * 3;
                    }
                    else if (decryptedChar >= 'A' && decryptedChar <= 'Z') {
                        score += freq[i];
                    }
                }
            }

            if (score > bestScore) {
                bestScore = score;
                bestChar = commonChar;
            }
        }
        referenceChar = bestChar;
    }

    int referenceIndex = alphabet.find(referenceChar);
    if (referenceIndex == string::npos) {
        referenceIndex = 0;
    }

    int shift = (mostFrequentIndex - referenceIndex + n) % n;
    return alphabet[shift];
}

string decryptVigenereWithAlphabet(const string& ciphertext, const string& key, const string& alphabet) {
    string plaintext;
    int keyLength = key.length();
    int n = alphabet.length();

    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        char k = key[i % keyLength];

        int cipherIndex = alphabet.find(c);
        int keyIndex = alphabet.find(k);

        if (cipherIndex != string::npos && keyIndex != string::npos) {
            int plainIndex = (cipherIndex - keyIndex + n) % n;
            plaintext += alphabet[plainIndex];
        }
        else {
            plaintext += '?';
        }
    }

    return plaintext;
}

struct DecryptionResult {
    string plaintext;
    string key;
    string alphabet;
    int keyLength;
    double probability;
};

bool compareByProbability(const DecryptionResult& a, const DecryptionResult& b) {
    return a.probability > b.probability;
}

void sortResultsByProbability(DecryptionResult results[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (results[j].probability < results[j + 1].probability) {
                DecryptionResult temp = results[j];
                results[j] = results[j + 1];
                results[j + 1] = temp;
            }
        }
    }
}

void kasiskiAttackWithNeuralNetwork(const string& ciphertext, const string& language, TextTypePerceptron& perceptron) {
    cout << "=== АТАКА КАЗИСКИ (" << (language == "russian" ? "русский" : "английский") << ") ===" << endl;
    cout << "Зашифрованный текст: " << ciphertext << endl;
    cout << "Длина текста: " << ciphertext.length() << " символов" << endl << endl;

    const int MAX_DISTANCES = 100;
    const int MAX_DIVISORS = 50;
    const int MAX_RESULTS = 100;

    int distances[MAX_DISTANCES];
    int distanceCount = 0;
    int divisorFreq[21] = { 0 };

    cout << "Поиск повторяющихся последовательностей..." << endl;
    cout << "=========================================" << endl;

    bool foundSequences = false;

    auto isValidChar = [&](char c) {
        if (language == "russian") return isRussianLetter(c);
        else return isEnglishLetter(c);
        };

    for (int len = 3; len <= 5; len++) {
        for (int i = 0; i <= ciphertext.length() - len; i++) {
            string sequence = ciphertext.substr(i, len);

            bool valid = true;
            for (int j = 0; j < len; j++) {
                if (!isValidChar(sequence[j])) {
                    valid = false;
                    break;
                }
            }
            if (!valid) continue;

            for (int j = i + len; j <= ciphertext.length() - len; j++) {
                string candidate = ciphertext.substr(j, len);
                if (sequence == candidate) {
                    if (!foundSequences) {
                        cout << "Найдены повторяющиеся последовательности:" << endl;
                        foundSequences = true;
                    }
                    int distance = j - i;

                    if (distanceCount < MAX_DISTANCES) {
                        distances[distanceCount++] = distance;
                    }
                    break;
                }
            }
        }
    }

    int possibleLengths[20];
    int possibleLengthsCount = 0;

    if (foundSequences) {
        cout << "АНАЛИЗ РАССТОЯНИЙ:" << endl;
        cout << "=================" << endl;

        cout << "Все расстояния: ";
        for (int i = 0; i < distanceCount; i++) {
            cout << distances[i] << " ";
        }
        cout << endl;

        int overallGCD = findGCD(distances, distanceCount);
        cout << "НОД всех расстояний: " << overallGCD << endl;

        for (int i = 0; i < distanceCount; i++) {
            int divisors[MAX_DIVISORS];
            int divisorCount = 0;
            findDivisors(distances[i], divisors, divisorCount);

            for (int j = 0; j < divisorCount; j++) {
                if (divisors[j] > 1 && divisors[j] <= 20) {
                    divisorFreq[divisors[j]]++;
                }
            }
        }

        cout << "\nСТАТИСТИКА ДЕЛИТЕЛЕЙ:" << endl;
        cout << "====================" << endl;

        int maxFreq = 0;
        for (int i = 2; i <= 20; i++) {
            if (divisorFreq[i] > 0) {
                cout << "Длина " << i << ": " << divisorFreq[i] << " упоминаний" << endl;
                if (divisorFreq[i] > maxFreq) {
                    maxFreq = divisorFreq[i];
                }
            }
        }

        cout << "\nВЕРОЯТНЫЕ ДЛИНЫ КЛЮЧА:" << endl;
        cout << "======================" << endl;

        for (int i = 2; i <= 20; i++) {
            if (divisorFreq[i] >= maxFreq / 2 && divisorFreq[i] > 0) {
                cout << ">>> " << i << " символов (упоминается " << divisorFreq[i] << " раз)" << endl;
                if (possibleLengthsCount < 20) {
                    possibleLengths[possibleLengthsCount++] = i;
                }
            }
        }

        if (overallGCD > 1 && overallGCD <= 20) {
            bool found = false;
            for (int i = 0; i < possibleLengthsCount; i++) {
                if (possibleLengths[i] == overallGCD) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << ">>> " << overallGCD << " символов (основано на НОД)" << endl;
                if (possibleLengthsCount < 20) {
                    possibleLengths[possibleLengthsCount++] = overallGCD;
                }
            }
        }
    }
    else {
        cout << "Не найдено повторяющихся последовательностей." << endl;
        cout << "Будем использовать стандартные длины ключа." << endl;
        for (int i = 2; i <= 10 && possibleLengthsCount < 20; i++) {
            possibleLengths[possibleLengthsCount++] = i;
        }
    }

    string alphabets[4];
    int alphabetCount = 0;
    getPossibleAlphabets(language, alphabets, alphabetCount);
    cout << "\nБудет использовано " << alphabetCount << " вариантов алфавита" << endl;

    cout << "\n=== НАЧИНАЕМ ПЕРЕБОР ВАРИАНТОВ ===" << endl;

    DecryptionResult allResults[MAX_RESULTS];
    int resultsCount = 0;
    int totalAttempts = 0;

    for (int a = 0; a < alphabetCount; a++) {
        const string& alphabet = alphabets[a];
        for (int k = 0; k < possibleLengthsCount; k++) {
            int keyLength = possibleLengths[k];
            if (keyLength > 15) continue;

            string groups[20];
            for (int i = 0; i < ciphertext.length(); i++) {
                groups[i % keyLength] += ciphertext[i];
            }

            string key;
            for (int i = 0; i < keyLength; i++) {
                char keyChar = frequencyAnalysisWithAlphabet(groups[i], alphabet, language);
                key += keyChar;
            }

            string plaintext = decryptVigenereWithAlphabet(ciphertext, key, alphabet);

            if (plaintext.length() > 10 && resultsCount < MAX_RESULTS) {
                double probability = perceptron.predict(plaintext, language);

                allResults[resultsCount].plaintext = plaintext;
                allResults[resultsCount].key = key;
                allResults[resultsCount].alphabet = alphabet;
                allResults[resultsCount].keyLength = keyLength;
                allResults[resultsCount].probability = probability;

                resultsCount++;
                totalAttempts++;

                cout << "Попытка " << totalAttempts << ": ключ=" << key << " (длина=" << keyLength
                    << "), вероятность=" << (probability * 100) << "%" << endl;
            }
        }
    }

    cout << "\n=== РЕЗУЛЬТАТЫ ПЕРЕБОРА ===" << endl;
    cout << "Всего протестировано вариантов: " << totalAttempts << endl;

    if (resultsCount == 0) {
        cout << "Не удалось найти ни одного подходящего варианта расшифровки." << endl;
        return;
    }

    sortResultsByProbability(allResults, resultsCount);

    cout << "\n=== ТОП-10 ЛУЧШИХ РЕЗУЛЬТАТОВ ===" << endl;
    for (int i = 0; i < min(10, resultsCount); i++) {
        const auto& result = allResults[i];
        cout << "\n--- РЕЗУЛЬТАТ " << (i + 1) << " ---" << endl;
        cout << "Вероятность: " << (result.probability * 100) << "%" << endl;
        cout << "Длина ключа: " << result.keyLength << endl;
        cout << "Ключ: " << result.key << endl;
        cout << "Алфавит: " << result.alphabet.substr(0, 10) << "..." << endl;
        cout << "Расшифрованный текст: " << result.plaintext.substr(0, 100)
            << (result.plaintext.length() > 100 ? "..." : "") << endl;
    }

    const auto& bestResult = allResults[0];
    cout << "\n*** ЛУЧШИЙ РЕЗУЛЬТАТ ***" << endl;
    cout << "Вероятность осмысленности: " << (bestResult.probability * 100) << "%" << endl;
    cout << "Тип текста: " << perceptron.getTextType(bestResult.probability) << endl;
    cout << "Длина ключа: " << bestResult.keyLength << endl;
    cout << "Ключ: " << bestResult.key << endl;
    cout << "Алфавит: " << bestResult.alphabet << endl;
    cout << "Полный расшифрованный текст:" << endl;
    cout << bestResult.plaintext << endl;
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    TextTypePerceptron perceptron;

    string russian_training_texts[10] = {
        "быстрая коричневая лиса прыгает через ленивую собаку это осмысленный русский текст научные исследования и эксперименты позволяют расширять границы познания вселенной и природы история человечества насчитывает многие тысячи лет непрерывного развития и эволюции цивилизации от древних времен до современной эпохи технологий",
        "криптография и информационная безопасность важные темы в компьютерной науке программирование требует логического мышления и внимательности к деталям при написании кода",
        "привет мир это простой тестовый пример для обучения нейронной сети современные технологии стремительно развиваются и меняют нашу повседневную жизнь кардинально литература и искусство помогают нам лучше понимать окружающий мир и самих себя через призму культурного наследия и творческого самовыражения людей",
        "искусственный интеллект и нейронные сети революционизируют технологии образование играет ключевую роль в развитии личности и профессиональном росте человека",
        "языки программирования такие как пайтон и си используются для разработки программ экономика страны зависит от многих факторов включая политическую стабильность и инвестиции",
        "йцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщфывапролджэячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапрол",
        "щшгнекуцйфывячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапролйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъ",
        "фывапролджэячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапролджэщшгнекуцйфывячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапролджэфывапролджэячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапролджэяфывапролджэячсмитьбюйцукенгшщзхъфывапролджэячсмитьбюйцукенгшщзхъфывапролджэ",
        "нейронные йцкен сети гшщз широко используются фыва в современных технологиях для распознавания образов и анализа сложных данных различных типов компьютерные йцкен технологии гшщз развиваются фыва очень быстро и оказывают значительное влияние на все сферы человеческой деятельности и жизни",
        "привет йцкен мир гшщз это кфыва смешанный текст с русским и случайным который содержит как осмысленные слова так и бессмысленные последовательности букв программирование йцукен это очень интересно гшщз но иногда бывает сложно фыва особенно когда приходится разбираться с сложными алгоритмами и структурами"
    };

    double russian_targets[10] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        0.0, 0.0, 0.0, 0.3, 0.5
    };

    string english_training_texts[10] = {
        "the quick brown fox jumps over the lazy dog this is meaningful english text programming languages such as python and javascript are used for developing complex software applications and web services",
        "cryptography and information security are important topics in computer science mathematics is a fundamental science for many modern fields including physics computer science and various engineering disciplines",
        "hello world this is a simple test example for neural network training literature and art help us better understand the world around us and ourselves through cultural heritage and creative expression",
        "artificial intelligence and neural networks are revolutionizing technology healthy lifestyle includes proper nutrition regular physical exercise and sufficient rest for maintaining optimal health condition",
        "programming languages such as python and c are used for software development the quick brown fox jumps over the lazy dog this is meaningful english text for neural network training and machine learning applications",
        "asdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiopzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnmqwertyuiopasdfghjklzxcvbnm",
        "zxcvbnmasdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiopzxcvbnmasdfghjklqwertyuiop",
        "qazwsxedcrfvtgbyhnujmikolpqazwsxedcrfvtgbyhnujmikolpqazwsxedcrfvtgbyhnujmikolpqazwsxedcrfvtgbyhnujmikolp",
        "neural qwert networks asdfg are widely used zxcvb in modern technologies for pattern recognition and complex data analysis encryption qwert and asdfg decryption zxcvb are important for information security and data protection",
        "hello qwert world asdfg this is zxcvb mixed text with english and random that contains both meaningful words and random sequences programming qwert is very interesting asdfg but sometimes can be zxcvb difficult especially when dealing with complex algorithms"
    };

    double english_targets[10] = {
        1.0, 1.0, 1.0, 1.0, 1.0,
        0.0, 0.0, 0.0, 0.3, 0.5
    };

    perceptron.train(russian_training_texts, russian_targets, 15000, "russian");
    perceptron.train(english_training_texts, english_targets, 15000, "english");

    while (true) {
        cout << "ВЗЛОМ ШИФРА ВИЖЕНЕРА" << endl;
        cout << "====================================================" << endl;
        cout << "\tВыход - 0;\n";
        cout << "Введите зашифрованный текст:" << endl;

        string input;
        getline(cin, input);

        if (input == "0") break;

        if (input.empty()) {
            cout << "Ошибка: текст не может быть пустым!" << endl;
            return 1;
        }

        string language = detectLanguage(input);
        if (language == "unknown") {
            cout << "Не удалось определить язык текста. Пожалуйста, введите текст на русском или английском языке." << endl;
            return 1;
        }

        cout << "Определен язык: " << (language == "russian" ? "РУССКИЙ" : "АНГЛИЙСКИЙ") << endl;

        string ciphertext = prepareText(input, language);

        if (ciphertext.length() < 30) {
            cout << "Внимание: для надежного анализа желательна длина текста от 50 символов." << endl;
            cout << "Текущая длина: " << ciphertext.length() << " символов." << endl;
        }

        kasiskiAttackWithNeuralNetwork(ciphertext, language, perceptron);
    }
    return 0;
}
```

<div align="center">

✨✨━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━✨✨

</div>