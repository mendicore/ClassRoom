#include <iostream>
#include <string>
#include "mll_1.h"

using namespace std;

void Allocate_Student(Addr_Student &P) {
   P=new Elmt_Student;
}

void Deallocate_Student(Addr_Student P) {
   delete P;
}

void CreateElm_Student(Addr_Student &P, Infotype_Student X) {
   Allocate_Student(P);
   Info(P)=X;
   Next(P)=Null;
}

void CreateEmptyList_Student(List_Student &L) {
   First(L)=Null;
}

void InsertFirst_Student(List_Student &L, Addr_Student P) {
   Next(P)=First(L);
   First(L)=P;
}

void InsertLast_Student(List_Student &L, Addr_Student P) {
   Addr_Student Q;

   if (First(L)==Null)//list L kosong
       First(L)=P;
   else {
      Q=First(L);
      while (Next(Q)!=Null) {
         Q=Next(Q);
      }
      Next(Q)=P;
   }
}

void InsertAfter_Student(Addr_Student P, Addr_Student Q) {
   //insert P after Q
   Next(P)=Next(Q);
   Next(Q)=P;
}

Addr_Student Search_Student(List_Student &L, string id) {
   Addr_Student P;
   
   P=First(L);
   while (P!=Null) {
   	   if (Info(P).id.compare(id) == 0) {
   	       return P;	
	   }
   }
   return P;
}

void DeleteFirst_Student(List_Student &L, Addr_Student &P) {
   P=First(L);
   if (Next(P)!=Null) {
   	  First(L)=Next(P);
   	  Next(P)=Null;
   }
}

void DeleteAfter_Student(Addr_Student Q, Addr_Student &P) {
   P=Next(Q);
   if (P!=Null) {
      Next(Q)=Next(P);
      Next(P)=Null;
   }
}

void DeleteById_Student(List_Student &L, string id, Addr_Student &P) {
   Addr_Student Q;

   P=Search_Student(L,id);
   Q=First(L);
   if (P==Q){
      DeleteFirst_Student(L,P);
   } else {
        while (Next(Q)!=P) {
            Q=Next(Q);
	    }
	    DeleteAfter_Student(Q,P);
   }
}

void DeleteByAddr_Student(List_Student &L, Addr_Student &P) {
   Addr_Student Q;

   Q=First(L);
   if (P==Q){
      DeleteFirst_Student(L,P);
   } else {
        while (Next(Q)!=P) {
            Q=Next(Q);
	    }
	    DeleteAfter_Student(Q,P);
   }
}

//=========================

void Set_Class(List_Student &L1, List_Class L2, string id, string id_class) {
   Addr_Student P;
   Addr_Class Q;
   
   P = Search_Student(L1,id);
   Q = Search_Class(L2,id_class);
   if (P!=Null && Q!=Null) {
   	  NextClass(P)=Q;
   }
}

//=========================

void Allocate_Class(Addr_Class &P) {
   P=new Elmt_Class;
}

void Deallocate_Class(Addr_Class P) {
   delete P;
}

void CreateElm_Class(Addr_Class &P, Infotype_Class X) {
   Allocate_Class(P);
   Info(P)=X;
   Next(P)=Null;
}

void CreateEmptyList_Class(List_Class &L) {
   First(L)=Null;
}

void InsertFirst_Class(List_Class &L, Addr_Class P) {
   Next(P)=First(L);
   First(L)=P;
}

void InsertLast_Class(List_Class &L, Addr_Class P) {
   Addr_Class Q;

   if (First(L)==Null)//list L kosong
       First(L)=P;
   else {
      Q=First(L);
      while (Next(Q)!=Null) {
         Q=Next(Q);
      }
      Next(Q)=P;
   }
}

void InsertAfter_Class(Addr_Class P, Addr_Class Q) {
   //insert P after Q
   Next(P)=Next(Q);
   Next(Q)=P;
}

Addr_Class Search_Class(List_Class &L, string id) {
   Addr_Class P;
   
   P=First(L);
   while (P!=Null) {
   	   if (Info(P).id_class.compare(id) == 0) {
   	       return P;	
	   }
   }
   return P;
}

void DeleteFirst_Class(List_Class &L, Addr_Class &P) {
   P=First(L);
   if (Next(P)!=Null) {
   	  First(L)=Next(P);
   	  Next(P)=Null;
   }
}

void DeleteAfter_Class(Addr_Class Q, Addr_Class &P) {
   P=Next(Q);
   if (P!=Null) {
      Next(Q)=Next(P);
      Next(P)=Null;
   }
}

void DeleteById_Class(List_Class &L, string id,Addr_Class &P) {
   Addr_Class Q;

   P=Search_Class(L,id);
   Q=First(L);
   if (P==Q){
      DeleteFirst_Class(L,P);
   } else {
        while (Next(Q)!=P) {
            Q=Next(Q);
	    }
	    DeleteAfter_Class(Q,P);
   }
}

void DeleteByAddr_Class(List_Class &L, Addr_Class &P) {
   Addr_Class Q;

   Q=First(L);
   if (P==Q){
      DeleteFirst_Class(L,P);
   } else {
        while (Next(Q)!=P) {
            Q=Next(Q);
	    }
	    DeleteAfter_Class(Q,P);
   }
}

void Delete_Class(List_Student &L1,List_Class &L2, string id_class) {
   Addr_Student P;
   Addr_Class Q;
   
   Q=Search_Class(L2,id_class);
   if (Q!=Null) {
      P=First(L1);
      while (P!=Null) {
      	 if (NextClass(P)==Q) {
      	    NextClass(P)=Null;	
		 }      	 
      	 P=Next(P);
	  }
	  DeleteByAddr_Class(L2,Q);
	  Deallocate_Class(Q);
   }
}


