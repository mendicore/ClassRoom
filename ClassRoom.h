#include <iostream>
#include <string>

using namespace std;

#define Null     		NULL
#define Info(P)  		(P)->Info
#define Next(P)  		(P)->Next
#define NextClass(P) 	(P)->NextClass
#define First(L) 		(L).First

//Kamus Global
typedef struct sElmt Elmt_Student;
typedef struct cElmt Elmt_Class;
typedef Elmt_Student* Addr_Student;
typedef Elmt_Class* Addr_Class;

typedef struct {
	string id;
	string name;
} Infotype_Student;

typedef struct {
	string id_class;
	string name;
} Infotype_Class;

typedef struct {
	Addr_Student First;
} List_Student;

typedef struct {
	Addr_Class First;
} List_Class;

struct sElmt {
   Infotype_Student Info;
   Addr_Student     Next;
   Addr_Class       NextClass;
};

struct cElmt {
   Infotype_Class Info;
   Addr_Class     Next;
};

void Allocate_Student(Addr_Student &P);
void Deallocate_Student(Addr_Student P);
void CreateElm_Student(Addr_Student &P, Infotype_Student X);
void CreateEmptyList_Student(List_Student &L);
void InsertFirst_Student(List_Student &L, Addr_Student P);
void InsertLast_Student(List_Student &L, Addr_Student P);
void InsertAfter_Student(Addr_Student P, Addr_Student Q);
Addr_Student Search_Student(List_Student &L, string id);
void DeleteFirst_Student(List_Student &L, Addr_Student &P);
void DeleteAfter_Student(Addr_Student Q, Addr_Student &P);
void DeleteById_Student(List_Student &L, string id, Addr_Student &P);
void DeleteByAddr_Student(List_Student &L, Addr_Student &P);

void Set_Class(List_Student &L1, List_Class L2, string id, string id_class);
Addr_Class Search_ClassOfStudent(List_Student &L, string id); //belum diimplementasi
void Print_StudentsOfClass(List_Student &L, string id_class); //belum diimplementasi

void Allocate_Class(Addr_Class &P);
void Deallocate_Class(Addr_Class P);
void CreateElm_Class(Addr_Class &P, Infotype_Class X);
void CreateEmptyList_Class(List_Class &L);
void InsertFirst_Class(List_Class &L, Addr_Class P);
void InsertLast_Class(List_Class &L, Addr_Class P);
void InsertAfter_Class(Addr_Class P, Addr_Class Q);
Addr_Class Search_Class(List_Class &L, string id);
void DeleteFirst_Class(List_Class &L, Addr_Class &P);
void DeleteAfter_Class(Addr_Class Q, Addr_Class &P);
void DeleteById_Class(List_Class &L, string id,Addr_Class &P);
void DeleteByAddr_Class(List_Class &L, Addr_Class &P);
void Delete_Class(List_Student &L1,List_Class &L2, string id_class);

