Анимационните герои Том и Джери са добри приятели и затова доста често си погаждат номера. След дълги наблюдения Том забелязал, че пъргавият му приятел, успокоен от своята ловкост, доста често си заспива където му падне. Котаракът веднага видял в това шанс да изпробва новия си летящ дрон, за да прави пакости, и да обвини Джери за това. Идеята му била да събуди Джери бутайки го по носа с дрона и по пътя евентуално да разлее цветна боя на някои места. Дронът на Том може да приема команди от следния тип


N(orth) — лети на север
S(outh) — лети на юг 
E(ast) — лети на изток
W(est) — лети на запад
P(aint) — разлей боя

Използвайки само тях, Том трябва да го “програмира”, за да реализира идеята си. Естествено има и някои ограничения:

в стаята има мебели, над които е опасно да се лети
батерията на дрона издържа за кратко и за това той не трябва да повтаря движенията си

За да завърши успешно мисията, котаракът трябва да вземе някои важни решения. Бързо осъзнал, че това е тежка задача, за която ще му трябва вашата помощ. Разполагате със следната информация, записана в текстов файл:

ред 1 — M N
размер на стаята
M е ширина, а N дължина
две цели числа, разделени с интервал
ред 2 — X1 Y1
позиция на Джери
две целочислени координати, разделени с интервал
координатната система, в която са описани всички координати, е с оси, успоредни на посоките на света. Началото на координатната система е  северозападният ъгъл на стаята, а осите Ox и Oy са ориентиране съответно от север към юг и от запад към изток
ред 3 — X2 Y2
позиция на Том, аналогично на горната
ред 4 — K L
K е броят на мебели в стаята
L е броят места подходящи за разливане на боя
K и L са разделени с интервал
следват описания на K мебели
ред 1 — X Y
позиция на северозападния ъгъл на мебелта
две целочислени координати, разделени с интервал
следва описание на формата на мебелта
мебелта се задава с правоъгълник от символи
символ ‘1’ означава наличие на мебел, а символ ‘␣’ означава липса на мебел
Пример:
111111
␣␣␣11
описанието на всяка мебел завършва с ред, който съдържа трите знака ===
следват L реда на позиции, подходящи за заливане с боя
всяка позиция се задава с целочислени координати, разделени с интервал

Примерен входен файл
4 4
0 2
3 0
2 1
2 1
11
 1
===
1 3
1
===
1 1

Въпросите, които силно интересуват Том са:

колко е дълъг най-късият път до Джери ?
кои са всички най-къси пътища от мен до Джери ?
колко боя ще разлея по всеки от пътищата ?
колко завоя ще направя по всеки от пътищата ?
какви команди да въведа в дрона ?
