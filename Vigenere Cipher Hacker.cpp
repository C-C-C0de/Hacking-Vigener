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