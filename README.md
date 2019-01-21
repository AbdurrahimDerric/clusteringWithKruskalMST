# clusteringWithKruskalMST
in turkish
clustering With Kruskal MST


Yontem
Problem tanimi:
Baglanti matrixi verilmis olan graphin, Kruskal MST algoritmasi
yardimiyla k tane benzerlik kumeye ayirmak.

Cozum:
Verilmis baglanti matrix’i kenarlar haline donusturmek
Ve Kruskal algoritmasi geregi bu keneralari siralamak .
Kenarlari sirayla gezerek alt kumeler olustururkan iki durum goz
onunde bulundurulur:
1.durum :
Alt kumelere label verirken label sayisi k’ye esit olmasi yani k
tane alt kume olustu fakat boslukta kalan dugumler var , bu
durumda yeni label vermeden kalan dugumlerinin ait oldugu
kenarlari gezerek labeled olan bir dugumle baglantisi var
Oldugu bir kenar rastalndiginda bu bos dugum ayni label yani
ayni kumeye yerlesir.

2.durum
Alt kumeler olusturuken bosta kalan dugumlerin sayisi arti
olusturulmus kume sayisi k’den daha kucuk olmasi , o durumda label
sayisi + bosta kalan dugumlerin sayisi buyuk k oldugu surece label
verilir aksi takdirde kalan bosta kalan dugumler sirayla gezilip labeli
artirarak ayri label verilir yani bir dugumden ibaret kumeler olusur.
