// CPP program to check for balanced brackets.
#include <bits/stdc++.h>
using namespace std;

// function to check if brackets are balanced
bool areBracketsBalanced(string expr)
{
    stack<char> s;
    char a, b, c;

    // Traversing the Expression
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            // Push the element in the stack
            s.push(expr[i]);
            continue;
        }

        // IF current current character is not opening
        // bracket, then it must be closing. So stack
        // cannot be empty at this point.
        if (s.empty())
            return false;

        switch (expr[i]) {
        case ')':

            // Store the top element in a
            a = s.top();
            s.pop();
            if (a == '{' || a == '[')
                return false;
            break;

        case '}':

            // Store the top element in b
            b = s.top();
            s.pop();
            if (b == '(' || b == '[')
                return false;
            break;

        case ']':

            // Store the top element in c
            c = s.top();
            s.pop();
            if (c == '(' || c == '{')
                return false;
            break;
        }
    }
    // Check Empty Stack
    return (s.empty());

}

// function to check if it is unmatched
int checkIfUnmatched(string expr) {
   
    stack<char> s;


    for (int i = 0; i < expr.length(); i++) {
        if (s.empty()) {
            s.push(expr[i]);
        }
        else if ((expr[i] == '(') || (expr[i] == '[') || (expr[i] == '{')) {
            s.push(expr[i]);
        }
        else if ((s.top() != '(' && expr[i] == ')') || (s.top() != '{' && expr[i] == '}') || (s.top() != '[' && expr[i] == ']')) {
            return i + 1;
        }
    }
    return 1; // to return 1 when the input is a single bracket
}

// line function
void Line() {
    cout << "------------------------------------------------------------------------" << endl;
}

// Driver code
    int main(){

    Line();
    string input_1 = "[]";
    cout << "Sample 1: ";
    // Function call
    if (areBracketsBalanced(input_1))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_1);
    
    cout << endl;

    Line();
    string input_2 = "{}[]";
    cout << "Sample 2: ";
    // Function call
    if (areBracketsBalanced(input_2))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_2);

    cout << endl;

    Line();
    string input_3 = "[()]";
    cout << "Sample 3: ";
    // Function call
    if (areBracketsBalanced(input_3))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_3);

    cout << endl;

    Line();
    string input_4 = "(())";
    cout << "Sample 4: ";
    // Function call
    if (areBracketsBalanced(input_4))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_4);

    cout << endl;

    Line();
    string input_5 = "{[]}()";
    cout << "Sample 5: ";
    // Function call
    if (areBracketsBalanced(input_5))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_5);

    cout << endl;

    Line();
    string input_6 = "{";
    cout << "Sample 6: ";
    // Function call
    if (areBracketsBalanced(input_6))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_6);

    cout << endl;

    Line();
    string input_7 = "{[}";
    cout << "Sample 7: ";
    // Function call
    if (areBracketsBalanced(input_7))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_7);

    cout << endl;

    Line();
    string input_8 = "foo(bar);"; // there's something strange about input 8
    cout << "Sample 8: ";
    // Function call
    if (areBracketsBalanced(input_8) + 1)
        cout << "Success";
    else
        cout << checkIfUnmatched(input_8);

    cout << endl;

    Line();
    string input_9 = "foo(bar[i);";
    cout << "Sample 9: ";
    // Function call
    if (areBracketsBalanced(input_9))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_9);

    cout << endl;

    Line();
    string input_41 = "ablabla)ihihi(ohoho";
    cout << "Sample 41: ";
    // Function call
    if (areBracketsBalanced(input_41))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_41);
    
    cout << endl;

    Line();
    string input_28 = "({})}";
    cout << "Sample 28: ";
    // Function call
    if (areBracketsBalanced(input_28))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_28) + 1;
    
    cout << endl;

    Line();
    string input_39 = "({(}";
    cout << "Sample 39: ";
    // Function call
    if (areBracketsBalanced(input_39))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_39);

    cout << endl;

    Line();
    string input_45 = "(([({{((({([[({{((((({(({{[[({([{[({[{({{[[[[({{(([([({({({([([[[[{{{[{({[{({([{{{[([{{{{({[(([{{({[(({(([(({[[([{[[(([({[{([(([[{([[{{([[{[({[([{[[({[[((([({[[[([({[{({([{{{(({[({{((({[{[[{[{{[{([{{[([{(({(({{{({{[([{{{{({{({[({[{({{{{({{[{[{(({[({[{({([([{[{({{[([{[(({{[{({((({([({{[[[({{[[[[[([[[([[[{[[{{[([[{[([{{{({{[{[{({[({[([{[{[{{[({({{([{([([[[[[{({{[({(([[[({[{[{[{({[{((([(({{[{([[({{({([(({{[{{(([{[{((((((((([{{([({[([{({([{{({{[{{[{(([[{(({{([([{[[{([{[({[{({[({[[[(({([[(({{[[{[[(({(({{{[{[[[[[[{[{{{{[(([([{[[{{[[([[(([[[{{([(([{(({{{{[[(([[[{{[([[{(({(([({{[[[([({[{{[[[(([{([(({[((([[([(({{{[{(([[{{{[([(([[({[[[({[((([[({{({{{[(({(([[([([([[([([{[[[[[(([[(({{(((([[({{{({{({([([{{[[[({([{[[([{([({{[[[{{([{[{({({[{((([{{(([[[{[({{({([{[{({(({(((((([({{{{[{({[{[{[{{({{{[[(([[([{([[((({{({(((([{[{{[{{({[[({[[[[[{{{((({{([{([{(([{(({[[({[[[({{[([{{([([{({{[({{[[[{([([[({({[[[[[{{({{[{{[{[[[[{([(([({(({{[({[[({([{([{(((({[(((([{([{{({{[({{[(({[(({[((([[[(([{{((([{([({{{((([({(())})])))}}})])}])))}}]))]]])))]}))]}))]}})]}})}}])}]))))]}))))}])}])})]]})]}}))})]))])}]]]]}]}}]}})}}]]]]]})})]])])}]]]}})]}})}])])}}])]}})]]]})]]}))}]))}])}])}})))}}}]]]]]})]]})}}]}}]}]))))})}})))]])}])]]))]]}}})}}]}]}]})}]}}}})]))))))}))})}]}])})}})]}]]]))}}])))}]})})}]}])}}]]]}})])}])]]}])})]]]}}])])})}})}}})]]))))}}))]]))]]]]]}])])]])])])]]))}))]}}})}})]])))]})]]]})]]))])]}}}]]))}]}}}))])]])))]}))])}]))]]]}}]})])]]]}})]))}))}]])]}}]]]))]]}}}}))}]))])}}]]]))]])]]}}]]}])]))]}}}}]}]]]]]]}]}}}))}))]]}]]}}))]])}))]]]})]})}]})]}])}]]}])])}}))}]]))}]}}]}})}}])})}])]})])}}])))))))))}]}]))}}]}}))])})}})]])}]}}))])))}]})}]}]}]})]]]))})]}})}]]]]])])}])}})})]}}]}]}])]})]})}]}]}})}}}])]}]])]}}]]}]]])]]])]]]]]}})]]]}})])})))})}]}}))]}])]}})}]}])])})}]})]}))}]}]}})}}}})}]})]})}})}}}}])]}})}}}))}))}])]}}])}]}}]}]]}]})))}})]}))}}}])})}]})])]]]})])))]]})]]}])]})]}]])}}]])}]]))])}]})]))]]}])]]}))]))}))]})}}]))]})}}}}])]}}}])})}]})}]}}}]]]])])})})})])]))}})]]]]}})}]})]}])})]]}}))})))))}})]])})))}})]))";
    cout << "Sample 45: ";
    // Function call
    if (areBracketsBalanced(input_45))
        cout << "Success";
    else
        cout << checkIfUnmatched(input_45);

    cout << endl;
    Line();
         
    return EXIT_SUCCESS;
}