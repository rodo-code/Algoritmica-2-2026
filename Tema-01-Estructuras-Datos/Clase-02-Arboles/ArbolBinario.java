public class ArbolBinario{
    static class Nodo{
        int valor;
        Nodo izq, der;

        Nodo(int valor) {
            this.valor = valor;
            this.izq = null;
            this.der = null;
        }
    }

    static class Arbol{
        Nodo raiz;

        Arbol(){
            this.raiz = null;
        }

        private Nodo insertar(Nodo nodoActual, int valor){
            if(nodoActual == null) return new Nodo(valor);
            if(valor < nodoActual.valor ){
                // Izquierda
                nodoActual.izq = insertar(nodoActual.izq,valor);
            }
            if(valor > nodoActual.valor){
                // Derecha
                nodoActual.der = insertar(nodoActual.der,valor);
            }
            return nodoActual;
        }

        public void insertar(int valor){
            this.raiz = insertar(raiz,valor); // Desde la raiz
            // buscando donde insertar el valor
        }

        private void preorder(Nodo nodo){
            if(nodo == null) return;
            // Procesar
            System.out.print(nodo.valor+" ");
            preorder(nodo.izq);
            preorder(nodo.der);
        }

        public void preorder(){
            preorder(raiz);
        }

        private void inorder(Nodo nodo){
            if(nodo == null) return;
            inorder(nodo.izq);
            // Procesar
            System.out.print(nodo.valor+" ");
            inorder(nodo.der);
        }

        public void inorder(){
            inorder(raiz);
        }

        private boolean buscar(Nodo nodo, int valor){
            if(nodo == null) return false;
            if(nodo.valor == valor) return true;
            else if(valor < nodo.valor) return buscar(nodo.izq,valor);
            else buscar(nodo.der,valor);
        }

        public boolean buscar(int valor){
            return buscar(raiz,valor);
        }
    }

    public static void main(String[] args) {
        Arbol arbol = new Arbol();
        arbol.insertar(5);
        arbol.insertar(3);
        arbol.insertar(8);
        arbol.insertar(4);
        arbol.insertar(1);
        arbol.insertar(7);
        arbol.insertar(10);
        arbol.inorder();
        System.out.println(arbol.buscar(7));
        System.out.println(arbol.buscar(50));
    }

}