Здесь я хочу объянить некоторые моменты в моём дз.<br/>
1.Вспомогательные функции:<br/>
ㅤ-file_to_string(path) - возвращает текст в типе string.<br/>
ㅤ-random_text_fragment_generator(path) - возвращает случайный фрагмент из текста до 4 слов подряд и до 20 символов.<br/>
ㅤ-is_there_equal_elements(vec) - считает процент одиннаковых элементов в векторе.<br/>
ㅤ-encoder(letter, index) - возвращает символ, смещенный на index % 26 элементов(индекс символа<br/>ㅤㅤв тексте + 1) вправо(в ascii).<br/>
ㅤ-decoder(letter, index) - декодирует зашифрованный символ.<br/>
2.Основные функции:<br/>
ㅤ-функции пронумерованны в соответствии с заданием<br/>
ㅤ-если функии first_b задать второй параметр true(по дефолту он равен false), то функция выведет map букв и их встречаемость.<br/>
ㅤ-во втором задании я сразу написал симметричный шифратор с +- равномерной статистикой встречаемости, поэтому нет функции second_c.<br/>
ㅤ-функции шифровальщики работают только с буквами.<br/>
