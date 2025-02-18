# Цель

Цель задания — продемонстрировать навыки проектирования ПО. 
Не беспокойтесь о производительности, использовании потоков или подключении библиотек. 
Мы не ожидаем детерминированного результата работы, это усложнило бы задачу.
Время выполнения не ограничено, но ожидается, что оно займет не более 6–8 часов.

## Что мы хотим увидеть:
1. Простой, аккуратный код, по которому легко понять, как он работает.
2. Четкие зоны ответственности каждой сущности в проекте.
3. Архитектуру, позволяющую легко добавлять новые сущности и механики взаимодействия.
    - Представьте, что после вас придут 10 джуниор-разработчиков, которые будут одновременно добавлять новые фичи.

# Задача

Создайте пошаговую симуляцию битвы юнитов на карте для экспериментов с механиками.

Можно создать карту размером W×H клеток и разместить на ней N юнитов.
- Юниты могут быть разного типа с разными действиями и характеристиками.
- Каждый юнит может выполнить одно действие за ход.
    - Юниты действуют в порядке их создания.
- Одну клетку может занимать только один юнит.
- У всех юнитов есть уникальный идентификатор **Id** (целое число) 
- У большинства юнитов есть характеристика **HP** (Health Points).
    - Если **HP** ≤ 0, юнит исчезает на следующий ход и больше не действует.
- Некоторые юниты могут перемещаться:
    - За ход могут переместиться в любую из восьми соседних клеток.
    - Если не могут достичь цели за один ход, продолжают двигаться к ней в следующих ходах.

Симуляция заканчивается, когда нет юнитов, способных действовать в следующем ходу, или на карте остается только один юнит.

## Юниты:

### Мечник
- **Характеристики:** HP, Strength
- **Ближний бой:** Бьет одного случайного юнита в соседней клетке, нанося ему **Strength** единиц урона.
- Если некого бить, перемещается.

### Охотник
- **Характеристики:** HP, Agility, Strength, Range
- **Дальний бой:** Стреляет в случайного юнита на расстоянии от 2 до **Range** клеток, нанося ему **Agility** единиц урона. Может стрелять только если в соседних клетках нет других юнитов.
- **Ближний бой:** Если стрелять не может, бьет одного случайного юнита в соседней клетке, нанося ему **Strength** единиц урона.
- Если некого бить, перемещается.

# Приложение

При запуске приложение получает путь к файлу со сценарием симуляции, где описаны **команды** для создания карты и юнитов, а также перемещения юнитов по карте. 
Приложение должно выводить все происходящие события в **stdout**.

Так как на карте нет препятствий, сложные алгоритмы поиска пути не требуются.

## Команды

- `CREATE_MAP W H` — Создает карту размером `W`×`H`. Эта команда начинает любой сценарий.
- `SPAWN_SWORDSMAN I X Y H S` — Создает мечника с идентификатором `I` в точке `X`,`Y` с характеристиками здоровья `H` и силы `S`.
- `SPAWN_HUNTER I X Y H A S R` — Создает охотника с идентификатором `I` в точке `X`,`Y` с характеристиками здоровья `H`, ловкости `A`, силы `S` и дальности `R`.
- `MARCH I X Y` — Приказывает юниту `I` переместиться в точку `X`,`Y`.

## События

- `MAP_CREATED` — Создание карты.
- `MARCH_STARTED`, `MARCH_ENDED` — Начало и конец перемещения юнита.
- `UNIT_SPAWNED`, `UNIT_DIED` — Создание и смерть юнита.
- `UNIT_MOVED` — Перемещение юнита на клетку.
- `UNIT_ATTACKED` — Атака одного юнита на другого.

Код парсера команд и вывода событий в лог уже содержится в проекте. Если необходимо, его можно менять. Формат ввода и вывода менять нельзя.

Пример сценария находится в файле _commands_example.txt_. Пример лога событий находится в файле _main.cpp_.

# Планы

При разработке учитывайте планы по добавлению новых юнитов, действий и характеристик. 

Эта функциональность не является частью задания, а лишь подсказывает направление при проектировании.

## Башня

- **Характеристики:** HP, Power
- **Дальний бой:** Стреляет в случайного юнита на расстоянии от 2 до 5 клеток, нанося ему **Power** единиц урона.
- Не может перемещаться.

## Лекарь

- **Характеристики:** HP, Spirit
- **Лечение:** Восстанавливает **Spirit** единиц здоровья одному случайному юниту в радиусе 2 клеток.
- Если некого лечить, перемещается.

## Ворон

- **Характеристики:** HP, Agility
- **Летающий юнит:**
    - Не занимает клетку на карте.
    - Может перемещаться на 2 клетки за ход.
    - Не может быть атакован ближнем боем.
    - Может быть атакован в дальнем бою, дистанция до юнита на единицу больше.
- **Ближний бой:** Бьет одного случайного юнита в соседних клетках, нанося ему **Agility** единиц урона.
- Если некого бить, перемещается.

## Мина

- **Характеристики:** Power
- Если в радиусе 2х клеток есть юнит - взрывается в следующем ходу, нанося всем юнитам в радиусе 3х клеток **Power** единиц урона.
- После взрыва исчезает.
- Не может перемещаться.
- Не может быть атакована.
- Не занимает клетку на карте.

# Технические требования

- **ОС:** Ubuntu
- **Компилятор:** clang 15+
- **Стандарт:** C++17 или новее
- **Система сборки:** cmake (в проекте должен быть CMakeLists.txt)
- Задание необходимо опубликовать в любом публичном гит-репозитории (GitHub, Bitbucket и т.д.).

_В процессе выполнения задания вы можете присылать любые вопросы._

# Ответы на вопросы.
#### Что делать если дали две команды MARCH одному юниту? Они их выполняют по очереди или происходить замена?
Происходит замена.
#### Что делаем с некорректными командами? Такие, как спавн двух юнитов в точке? Просто отмена команды и вывод в лог? Или остановка симуляции?
Отмена команды и вывод в лог
#### "юнит исчезает на следующий ход" - то есть в этом ходу он стоит и его "труп" атакуют? А если не атакуют, то это препятствие?
По логике не атакуют, и действительно, тогда это препятствие. Требований к алгоритмам поиска пути нет, поэтому решение обхода трупа на ваше усмотрение, пусть даже случайный шаг в любом направлении. 
Пояснение: алгоритм поиска пути просто ищет ближайшую к цели марша из доступных точек. Точка с телом это наземное препятствие. Если доступных позиций нет, то просто ждём.  
#### Для нас критично, что симуляция продлится на один ход больше, чем могла бы? Если нет, то это упрощает логику.
Не критично. Однако будет интересно послушать об альтернативах и причине такого решения.
Пояснение: архитектура программы такова, что все AI* оповещают симуляцию было ли совершено какое-либо действие. То есть, нам проще провести ещё один ход - где все AI не совершат действия, чем пытаться проверить можно ли совершить действие в следующем ходу.
# Особенности
#### Ожидание == действие.
К примеру, если юнит окружён телами, он ждёт когда они исчезнут. При этом считаем, что он таким образом совершил некое действие.
#### Dead lock.
Есть варианты использования кода когда симуляция может работать "бесконечно" долго. К примеру, мы создали юнита с громадным количеством хп. Или прописали новый AI юнитов которые не могут атаковать, при этом у них одинаковая позиция марша. Считаем, что подобный дед лок это ожидаемый результат симуляции. То есть, при помощи симуляции мы поняли, что при данных параметрах/изменении AI получаем дед лок. 
# Определения
#### Entity
Логически отделимая сущность. Юнит, игровое поле, куча юнитов. и т. п.
#### Механика
Необходимая минимальная реакция внутренних сущностей симуляции на действие. К примеру, шаг - это изменение значения полей GameField отвечающих за позицию игрока, в ответ на запрос о шаге.
#### AI* - искусственный интеллект
Класс использующий механики для реализации какого либо поведения. К примеру, марш. Использует механику шага, для реализации поведения марша. Следовательно, марш описывается AI*.
#### pAI*
Часть AI описывает то, как AI использует механики. Требуется для более удобного реиспользования механик AI.
#### Симуляция
Координирует взаимодействие и поведение AI над сущностями программы.
