## Invertieren eines Integer-Arrays

Unter dem Invertieren eines Arrays versteht man "Umdrehen" der Elemente der Elemente des Arrays.
Im engeren Sinne werden die Elemente des Arrays vertauscht.
Das Invertieren benötigt eine Vertauschungsoperation, mit der man z.B. das erste und das letzte Element des Arrays tauscht.

Bsp.:

Das Ausgangsarray
int a[3] = {1, 2, 3 }
a[0] => 1

Das invertierte Array

a[3]={3, 2, 1}

Prozess des Vertauschens

tmp = a[0]  tmp=>1
a[0]=a[2] =>a = {3, 2, 3}
a[2] =tmp	a=> {3, 2, 1}
