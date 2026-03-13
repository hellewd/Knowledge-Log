// Facundo Ahumada, 21-869.762-3

// Se utilizará inglés, para poder lograr y llevar una mejor práctica, pero los textos nuestros serán en español.
public class tmp001 {
    // Creamos función donde se obtiene un número aleatorio entre x e y
    private static int getRandom(int x, int y) {
        return (int) (Math.random() * (y - x + 1) + x);
    }
    // Creamos función donde se llena el array con números aleatorios
    private static void fillArray(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            arr[i] = getRandom(3, 9);
        }
    }
    // Creamos función donde se muestra el array
    private static void showArray(int[] arr, String title) {
        System.out.println(title);
        for(int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
        System.out.println(); // para hacer simplemente un salto de línea
    }
    // Creamos función donde se obtiene el valor mínimo
    private static void obtainedMin(int[] arr) {
        int min = arr[0];
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] < min) {
                min = arr[i];
            }
        }
        System.out.println("El valor mínimo es: " + min);
    }
    // Creamos función donde se obtiene el valor máximo
    private static void obtainedMax(int[] arr) {
        int max = arr[0];
        for(int i = 1; i < arr.length; i++) {
            if(arr[i] > max) {
                max = arr[i];
            }
        }
        System.out.println("El valor máximo es: " + max);
    }
    // Creamos función donde se obtiene el promedio
    private static void obtainedProm(int[] arr) {
        double prom = 0;
        // Sumamos todos los valores del arreglo
        for(int i = 0; i < arr.length; i++) {
            prom += arr[i];
        }
        prom = prom / arr.length;
        System.out.println("El promedio es: " + prom);
    }
    // Creamos función que nos dice cuántas veces se repite cada número; solamente si aparece más de 1 vez; si ya aparecio, no se hace la contabilidad nuevamente.
    private static void obtainedRepeated(int[] arr) {
        for(int i = 0; i < arr.length; i++) {
            int count = 0;
            for(int j = 0; j < arr.length; j++) {
                if(arr[i] == arr[j]) {
                    count++;
                }
            }
            // Verificamos si ya se repitió este número anteriormente
            boolean repeated = true;
            for(int j = 0; j < i; j++) {
                if(arr[i] == arr[j]) {
                    repeated = false; // Cambiamos simplemente su estado
                    break;
                }
            }
            // Si se repite más de 1 vez y no se ha mostrado antes; aparece
            if(count > 1 && repeated) {
                System.out.println("El número " + arr[i] + " se repite " + count + " veces");
            }
        }
    }
    // Función principal
    public static void main(String[] args) {
        int[] arr = new int[10];
        fillArray(arr);
        showArray(arr, "Array generado:");
        obtainedMin(arr);
        obtainedMax(arr);
        obtainedProm(arr);
        obtainedRepeated(arr);
    }
}
