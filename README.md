# struktur-data-h-praktikum-3-2021

## Kata-kata
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/kk_bukti.png)
### Penjelasan Soal
Diberikan `n` kata yang disimpan [a-z]. Untuk setiap `q`, cari apakah kata tersimpan (output `1`) atau tidak (output`0`).
### Penjelasan Solusi
Program menggunakan [implementasi ADT Trie](https://github.com/Doanda37Rahma/struktur-data-h-asistensi-3-2021#implementasi-dalam-c), sebuah tree yang menyimpan data string. Sebuah node memiliki bool yang menandakan akhir kata, dan pointer ke huruf selanjutnya.
Program menggunakan [fungsi insert()](https://github.com/Doanda37Rahma/struktur-data-h-asistensi-3-2021#fungsi-insert) untuk memasukkan kata. Kemudian, program mencari kata dengan [fungsi search()](https://github.com/Doanda37Rahma/struktur-data-h-asistensi-3-2021#fungsi-search). `search()` hanya mengembalikan `1` jika saat menelusuri cabang trie tidak menemukan null dan huruf terakhir adalah leaf(ditandai bool).
### Visualisasi Solusi
Sample Input:
```
3
soalnya
mudah
dipahami
3
dan
soalnya
singkat
```
Sample Output:
```
0
1
0
```
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/kk_visual.png)


## MALUR NGULI
### Verdict
AC saat Revisi
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/mn_bukti.png)
### Penjelasan Soal
Diberikan sebuah AVL Tree, program diminta menghitung dan mengoutput jumlah setiap kolom dalam tree
### Penjelasan Solusi
Disini penting untuk mengidentifikasi perbedaan horizontal antara node dengan root. Perbedaan ini direpresentasikan dalam index dua array `rightSum` untuk bagian kanan/tengah dan `leftSum` untuk bagian kiri tree (jaraknya dinegatifkan).
```
struct AVL
{
private:
...
	int rightSum[MAX_ARR],
	leftSum[MAX_ARR],
	rightDistance,
	leftDistance;
...
```
#### Fungsi `_findLeftDistance()` dan `_findRightDistance()`
Sebelumnya, karena menggunakan array static, maka perlu menentukan batas-batas/range index nya:
Kedua fungsi ini menelusuri tree dari center ke ujung kanan dan kiri dan mengembalikan jarak maksimal node paling kiri dan kanan tree terhadap node root
```
    int _findLeftDistance(AVLNode* node)
    {
        int ld=0;
        while (node && node->left) {
            node = node->left;
            ld++;
        }
        return ld;
    }
 
    int _findRightDistance(AVLNode* node) {
        int rd=0;
        while (node && node->right) {
            node = node->right;
            rd++;
        }
        return rd;
    }
```
#### Fungsi `_updateSum()`
Fungsi ini adalah fungsi yang menelusuri tree untuk mengupdate isi array (jumlah tiap kolom). 
```
   void _updateSum(AVLNode *node, int index)
    {
        if (node != NULL) {
            if (index>=0) {  // untuk bagian kanan tree
                rightSum[index]+=node->data;    // menambah jumlah suatu kolom
            }
            else if (index<0) {  // untuk bagian kiri tree
                if (index*-1>leftDistance)  // jika terdapat node yang lebih dalam dan lebih kiri dari tree, 
                    leftDistance++;		// maka jarak kiri maksimal juga diupdate
                leftSum[index*-1]+=node->data;   // menambah jumlah suatu kolom
            }
            _updateSum(node->left, index-1);  // telusur ke kanan
            _updateSum(node->right, index+1);  //         ke kiri
        }
    }
```
#### Fungsi `printVerticalSum()`
Fungsi ini merupakan fungsi utama untuk mengeluarkan output
```
    void printVerticalSum() {
        leftDistance = _findLeftDistance(_root);    // mencari jarak kiri maks
        rightDistance = _findRightDistance(_root);  // mencari jarak kanan maks
        for (int i=0; i<MAX_ARR; i++) {		// mengisi array dengan 0
        	leftSum[i] = rightSum[i] = 0;
		}
        _updateSum(_root, 0);  // menjumlah sum tiap kolom
        for (int i=leftDistance; i>0 ;i--) {  // mengeluarkan sum dari kolom kiri paling jauh (jarak ke kiri terbesar)
            cout << leftSum[i] << " ";
        }
        for (int i=0 ; i<=rightDistance ; i++) {  // mengeluarkan sum dari kolom terdekat (jarak 0) ke kanan
            cout << rightSum[i] << " ";
        }
        cout << endl;
	}
```
#### Fungsi `main()`
Dalam fungsi main, program menerima antara dua command, jika `insert` maka memasukkan angka ke dalam tree, dan jika `print` maka mengoutputkan jumlah setiap kolom tree yang ada
```
int main()
{
    AVL tree;
    tree.init();

    int t;
    char s[101];

    cin >> t;
    for (int i=0; i<t; i++) {
	    scanf("%s", s);
	    string cmd = s;
	        if (cmd == "insert") {
	            int x;
	            scanf("%d",&x);
	            tree.insert(x);
	        } else if (cmd == "print") {
	            if (!tree.isEmpty()) 
		            tree.printVerticalSum();
	        }
    }
    return 0;
}
```


### Visualisasi Solusi
Contoh Input:
```
9
insert 20
insert 10
insert 15
insert 9
insert 6
insert 25
insert 24
insert 26
print
```
Contoh Output:
```
6 9 45 24 25 26 
```
Disini setiap kolom tree terlihat seperti ini

![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/mn_visual.png)


## Cayo Niat
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/cn_bukti.png)
### Penjelasan Soal
Diberikan kata-kata yang dipisah oleh whitespace, program diminta mengeluarkan output terurut secara abjad: pertama, dengan format penomoran (mulai 1.) perbaris, kedua, dipisah oleh "--<3--" dalam satu baris
### Penjelasan Solusi
#### Fungsi `main()`
Program menggunakan AVL Tree untuk menyimpan data tipe string. Untuk setiap kata akan dimasukkan ke dalam tree.
>>Dalam hackerrank, jika ada loop cin tanpa henti maka menginput kata terakhir yang diinput, maka untuk menghentikan stream input apabila sama dg input sebelumnya.
```
int main(int argc, char const *argv[])
{
    AVL set;
    set.init();
	
	char s[LEN], p[LEN];
		
    strcpy(p,"x");
    for (int i=0; i<1000; i++)
    {
        cin >> s;
        if (!strcmp(p,s)) break;
        strcpy(p,s);
        set.insert(s);
    }	
    
    set.inorderNumbered();
    set.inorderString();
	
    return 0;
}
```
Untuk mengoutputkan secara abjad, terdapat dua fungsi inorder sesuai format:
#### Fungsi `inorderNumbered()`
```
    void inorderNumbered () {
    	this->_inorderNum(_root);
    	count = 1;  // var untuk penomoran
    }

    void _inorderNum(AVLNode *node) {
        if (node) {
            _inorderNum(node->left);
            printf("%d. %s\n", count, node->data);  // print sesuai format penomoran
            count++;  // penomoran selanjutnya
            _inorderNum(node->right);
        }
    }
		
```
#### Fungsi `inorderString()`
```
	void inorderString () {
		this->_inorderS(_root);
		printf("\n");
	}

    void _inorderS(AVLNode *node) {
        if (node) {
            _inorderS(node->left);
            printf("%s",node->data); // print kata
            if (count < _size)  // memastikan agar "--<3--" tidak diprint setelah kata terakhir
	            printf("--<3--");
            count++;
            _inorderS(node->right);
        }
    }
	
```

### Visualisasi Solusi
```
Sample Input 0

Mas      Erki  Guanteng    Poll
 
      Mas     Rifki        Baik Poll
  
 Mba                 Inez  Makan   Cintaku   
 
        Aku    Benci   Soal Banyu
  
CANDA        Mas Daniel    Saranghae Asdos SDH
```
Sample Output 0
```
1. Aku
2. Asdos
3. Baik
4. Banyu
5. Benci
6. CANDA
7. Cintaku
8. Daniel
9. Erki
10. Guanteng
11. Inez
12. Makan
13. Mas
14. Mba
15. Poll
16. Rifki
17. SDH
18. Saranghae
19. Soal
Aku--<3--Asdos--<3--Baik--<3--Banyu--<3--Benci--<3--CANDA--<3--Cintaku--<3--Daniel--<3--Erki--<3--Guanteng--<3--Inez--<3--Makan--<3--Mas--<3--Mba--<3--Poll--<3--Rifki--<3--SDH--<3--Saranghae--<3--Soal
```

## Part Time
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/pt_bukti.png)
### Penjelasan Soal
Diberikan data indeks `m` barang (`p`) dan harganya (`q`), serta `n` query transaksi berisi jumlah pembelian (`x`) dan id (`y`). Program diminta mengeluarkan total pendapatan, `Maaf barang tidak tersedia` jika barang tidak ditemukan, dan jika input id tidak urut keluarkan `ID harus urut` dan akhiri program.
### Penjelasan Solusi
```
int main() {
	
	int num[MAX];
	int m,n,p,q,x,y;
	int sum=0;
	scanf("%d %d", &m,&n);
	int i;
	for(i=0; i<m; i++) {
		scanf("%d %d", &p,&q);
		if (p != i+1) {
			printf("ID harus urut\n");
			return 0;
		}
		num[p] = q;
	}
	
	for(i=0; i<n; i++) {
		scanf("%d %d", &x,&y);
		if (y<1 || y>m) {
			printf("Maaf barang tidak tersedia\n");
			continue;
		}
		sum += x * num[y];
	}
	
	printf("%d\n", sum);
    return 0;
}
```
Program menyimpan data barang menggunakan array. Pertama, program menyimpan `m` dan `n`, kemudian menyimpan data
### Visualisasi Solusi
Sample Input 0
```
10 7
1 65000
2 13700
4 37800
```
Sample Output 0
```
ID harus urut
```
Jika input id tidak urut dari input sebelumnya, keluarkan
Sample Input 1
```
5 5
1 13000
2 5500
3 8750
4 21900
5 30000
4 4
2 3
2 1
1 7
3 2
```
Sample Output 1
```
Maaf barang tidak tersedia
147600
```

![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/pt_visual.png)

## Bucyn
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/b_bukti.png)
### Penjelasan Soal
Terdapat dua
### Penjelasan Solusi
### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/b_visual.png)

## Nadut Belajar
### Verdict
AC saat Praktikum
### Bukti
![BUKTI](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/nb_bukti.png)
### Penjelasan Soal
Program diminta menghitung selisih parent node dengan siblingnya
### Penjelasan Solusi
```
int main(int argc, char const *argv[])
{
    AVL avl;
    avl.init();
    
	int Q,T,n,t;
	cin >> Q >> T;
	for (int i=0; i<Q; i++) {
		cin >> n;
		avl.insert(n);
	}
	for (int i=0; i<T; i++) {
		cin >> t;
		cout << avl.parentSiblingDiff(t) << endl;
	}
	
    return 0;
}
```
Program menggunakan ADT AVL tree dengan parrent.
#### Fungsi `parentSiblingDiff()`
Berikut fungsi `parentSiblingDiff()` dan penjelasannya
```
    int parentSiblingDiff(int value) {
        
        AVLNode *temp = _search(_root, value);
        if (temp!=NULL) {
            if (temp->parent) { // jika node punnya parent, jika tidak(node=root) keluar 0
                if (temp->parent->parent) {  // jika parent node juga punya parent, jika tidak maka keluarkan nilai node itu
                    if (temp->parent->parent->left && temp->parent->parent->right) {  // jika parent node memiliki sibling, hitung perbedaan mutlak
                        int l=temp->parent->parent->left->data;
                        int r=temp->parent->parent->right->data;
                        return (l < r) ? r-l : l-r; 
                    } else {
                        return temp->parent->data;
                    }
                } else {
                    return temp->parent->data;
                }
            }
            return 0;
        }
        return 0;
}
```
### Visualisasi Solusi
![VISUAL](https://github.com/Doanda37Rahma/struktur-data-h-praktikum-3-2021/blob/main/img/nb_visual.png)


