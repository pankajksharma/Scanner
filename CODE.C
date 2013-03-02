 
struct node{
  char data[64];
  struct node *next;
 };
struct node *firsta, *currenta, *newa;
 
int main(void)
{
 int k;
 scanf("%d", &k);
 
 struct node *head=NULL;
 
 do{
  switch(k){
   case 1: addnew();
   break;
 
  }while(k!=0);
 
 void addnew(void)
{
 struct node *newnode=malloc(sizeof(struct node));
   
 if (head=NULL)
  firsta=newa=currenta;
 else
 {
  currenta=firsta;
   while(currenta->next!=NULL)
    currenta=currenta->next;
 
   currenta->next=newa;
   currenta=newa;
}
 
gets(currenta->data);
 
currenta->next=NULL;
}