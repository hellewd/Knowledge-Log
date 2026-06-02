/*
# Orden: Raiz 45
23 < 45 Izq --> 12 < 34 12(izq) 34(der)
67 > 45 Der --> 56 < 89 56(izq) 89(der)

# in-Order:
12 23 34 45 56 67 89
*/

public class Tree {
// Creamos el nodo base.
    static class Node {
        int valor;
        Node izquierda, derecha;
        
        Node(int valor) {
            this.valor = valor;
        }
    }

    Node raiz;

    Node insertar(Node nodo, int valor) {
        if (nodo == null) {
            return new Node(valor);
        }
        
        if (valor < nodo.valor) {
            nodo.izquierda = insertar(nodo.izquierda, valor);
        } else if (valor > nodo.valor) {
            nodo.derecha = insertar(nodo.derecha, valor);
        }
        
        return nodo;
    }

    void inOrder(Node nodo) {
        if(nodo != null) {
            inOrder(nodo.izquierda);
            System.out.print(nodo.valor + " ");
            inOrder(nodo.derecha);
        } 
    }

    public static void main(String[] args) {
        Tree tree = new Tree();
        int[] valores = {45, 23, 67, 12, 34, 56, 89};
        
        for (int valor : valores) {
            tree.raiz = tree.insertar(tree.raiz, valor);
        }

        System.out.println("23 < 45 # va a la IZQUIERDA de la raíz #");

        System.out.print("In-order: ");
        tree.inOrder(tree.raiz);
    }
}
