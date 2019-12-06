
#include "Scanner.h"
#include "Stack.h"  // GENERIC STACK

#include <iostream>
using namespace std;



int main () {
    Scanner S(cin);
    Token t;

    Stack<Token> numstack, opstack;  // 2x Stacks of type Token
    
    Token num1, num2, op;
    t = S.getnext();

    while ( t.tt!=eof || !opstack.isEmpty() ) {
      if (t.tt==integer) {
        numstack.push(t);
        t=S.getnext();
      } else if (t.tt==lptok) {
        opstack.push(t);
        t=S.getnext();
      } else if (t.tt==rptok) {
        if (opstack.peek().tt==lptok) {
          opstack.pop();
          t=S.getnext();
        } else {
          num2=numstack.pop();
          num1=numstack.pop();
          op=opstack.pop();
          switch (op.tt) {
            case asttok:
              num1.val= num1.val * num2.val;
            case slashtok:
              num1.val= num1.val / num2.val;
            case pltok:
              num1.val= num1.val + num2.val;
            case mitok:
              num1.val= num1.val - num2.val;
          }
          numstack.push(num1);
        }
      } else if ( t.tt==pltok || t.tt==mitok || t.tt==eof ) {
        if (!opstack.isEmpty() && (opstack.peek().tt==pltok || opstack.peek().tt==mitok || opstack.peek().tt==asttok || opstack.peek().tt==slashtok ) ) {
          num2=numstack.pop();
          num1=numstack.pop();
          op=opstack.pop();
          switch (op.tt) {
            case asttok:
              num1.val= num1.val * num2.val;
            case slashtok:
              num1.val= num1.val / num2.val;
            case pltok:
              num1.val= num1.val + num2.val;
            case mitok:
              num1.val= num1.val - num2.val;
          }
          numstack.push(num1);
        } else {
          opstack.push(t);
          t=S.getnext();
        }
      } else if (t.tt==asttok || t.tt==slashtok) {
        if (!opstack.isEmpty() && (opstack.peek().tt==asttok || opstack.peek().tt==slashtok) ) {
          num2=numstack.pop();
          num1=numstack.pop();
          op=opstack.pop();
          switch (op.tt) {
            case asttok:
              num1.val= num1.val * num2.val;
            case slashtok:
              num1.val= num1.val / num2.val;
          }
          numstack.push(num1);
        } else {
          opstack.push(t);
          t=S.getnext();
        }
      }
    } 
    cout << numstack.pop().val<< endl;
    return 0;
}
