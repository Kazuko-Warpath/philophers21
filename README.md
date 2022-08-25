# philophers21
В этом проекте вы изучите основы многопоточности процесса.Вы увидите, как создавать потоки, и откроете для себя мьютексы.
Общие правила:

Один или несколько философов сидят за круглым столом. Посреди стола стоит большая миска со спагетти.
Философы альтернативно едят, думают или спят.
во время еды они не думают и не спят;
во время мышления они не едят и не спят;
и, конечно, во время сна они не едят и не думают.
На столе тоже есть вилки. Вилок столько же, сколько философов.
Поскольку подавать и есть спагетти только одной вилкой очень неудобно, философ берет правую и левую вилки, чтобы поесть, по одной в каждую руку.
Когда философ заканчивает есть, они кладут вилки обратно на стол и начинают спать. Проснувшись, они снова начинают думать. Симуляция прекращается, когда философ умирает от голода.
Каждый философ должен есть и никогда не должен голодать.
Философы не разговаривают друг с другом.
Философы не знают, умрет ли другой философ.
Нет нужды говорить, что философы должны избегать смерти!
Правила для основной части:

Каждый философ должен быть потоком.
Между каждой парой философов есть одна развилка. Поэтому, если есть несколько философов, то у каждого философа есть вилка с левой стороны и вилка с правой. Если есть только один философ, то на столе должна быть только одна вилка.
Чтобы философы не дублировали вилки, вы должны защитить состояние вилки с помощью мьютекса для каждой из них.

Глобальные правила:

Глобальные переменные запрещены!
Ваша программа должна принимать следующие аргументы:
number_of_philosophers (количество философов, а также количествовилок.)
time_to_die ((в миллисекундах): Если философ не начал есть time_to_die миллисекунды с начала своего последнего приема пищи или начала симуляции, он умирает.)
time_to_eat ((в миллисекундах): время, необходимое философу, чтобы поесть. За это время им нужно будет держать две вилки.)
time_to_sleep ((в миллисекундах): время, которое философ проведет во сне.)
[number_of_times_each_philosopher_must_eat] ((необязательный аргумент): Если все философы съели хотя бы number_of_times_each_philosopher_must_eat раз, симуляция прекращается. Если не указано иное, моделирование прекращается, когда философ умирает.)
Каждый философ имеет число в диапазоне от 1 до number_of_philosophers.
Философ номер 1 сидит рядом с философом номер number_of_philosophers. Любой другой философ номер N находится между философом номер N - 1 и философом номер N + 1.
О журналах вашей программы:

Любое изменение состояния философа должно быть отформатировано следующим образом:
timestamp_in_ms X has taken a fork
timestamp_in_ms X is thinking
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X is died
(Замените timestamp_in_ms текущей меткой времени в миллисекундах, а X - числом философа.)

Отображаемое сообщение о состоянии не должно смешиваться с другим сообщением.
Сообщение о смерти философа должно отображаться не более чем через 10 мс после его фактической смерти.
Опять же, философы должны избегать смерти!
