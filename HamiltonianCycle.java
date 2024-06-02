
import java.util.ArrayList;
import java.util.Scanner;


public class HamiltonianCycle {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

     /*System.out.print("Enter the number of vertices: ");
        int numVertices = scanner.nextInt();
        
        int graph[][] = new int[numVertices][numVertices];

        System.out.println("Enter the adjacency matrix:");
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++) {
                graph[i][j] = scanner.nextInt();
            }
        }*/
       // 
       int [][]graph2={
           {0,1,0,1,0,0,0,1},
           {1,0,1,0,0,0,0,1},
           {0,1,0,1,0,0,0,0},
           {1,0,1,0,1,0,0,1},
           {0,0,0,1,0,1,0,1},
           {0,0,0,0,1,0,1,0},
           {0,0,0,0,0,1,0,1},
           {1,1,0,0,1,0,1,0}
             
       };
       
        
        System.out.println();
        ArrayList<Integer> cycle = new ArrayList<>();

        for (int i = 0; i < graph2[0].length; i++) {
           cycle.add(-1);
        }

         ArrayList<ArrayList<Integer>> all_possible = new ArrayList<>();
         hamiltonianCycle(all_possible,graph2,cycle,0);
          for (ArrayList<Integer> combination : all_possible) {
            System.out.println(combination);
        }
         
         
         
    }
    
     static void hamiltonianCycle(ArrayList<ArrayList<Integer>> set, int matrix[][], ArrayList<Integer> cycle, int i) {
    
    do {
            nextValue(i, cycle, matrix);
            if (cycle.get(i) == 0 && i!=0)
                return;
            if (i == cycle.size()-1) {
                set.add(new ArrayList<>(cycle));
            } else {
              hamiltonianCycle(set, matrix, cycle, i + 1);
            }
        } while (true);
     }
    
     public static void nextValue(int i, ArrayList<Integer> cycle, int matrix[][]) {
        do {
            int j = 0;
            int nextCol = (cycle.get(i) + 1) % (matrix.length + 1);
            cycle.set(i, nextCol);

            if (nextCol == 0 && i!=0) {
                return;
            }
            
            if(matrix[cycle.get(i-1)][cycle.get(i)]!=0){
            for (j = 0; j < i-1; j++) {
                if (cycle.get(j) == nextCol) {
                    cycle.remove(cycle.size()-1);
                    break;
                }
            }
            if (j == i-1) {
                if((i<matrix.length)|| matrix[cycle.get(i)][cycle.get(matrix.length)]!=0 ){
                    

                return;
                }
            }
            }
        } while (true);
    }
}


/*import java.util.*;
//import java.util.Scanner;



public class HamiltonianCycle {

    public static void main(String[] args) {
        int[][] graph2 = {
                {0, 1, 0, 1, 0, 0, 0, 1},
                {1, 0, 1, 0, 0, 0, 0, 1},
                {0, 1, 0, 1, 0, 0, 0, 0},
                {1, 0, 1, 0, 1, 0, 0, 1},
                {0, 0, 0, 1, 0, 1, 0, 1},
                {0, 0, 0, 0, 1, 0, 1, 0},
                {0, 0, 0, 0, 0, 1, 0, 1},
                {1, 1, 0, 0, 1, 0, 1, 0}
        };

        System.out.println();
        ArrayList<Integer> cycle = new ArrayList<>();

        for (int i = 0; i < graph2.length; i++) {
            cycle.add(-1);
        }

        ArrayList<ArrayList<Integer>> all_possible = new ArrayList<>();
        hamiltonianCycle(all_possible, graph2, cycle, 0);
        for (ArrayList<Integer> combination : all_possible) {
            System.out.println(combination);
        }
    }

    static void hamiltonianCycle(ArrayList<ArrayList<Integer>> set, int matrix[][], ArrayList<Integer> cycle, int i) {
        do {
            nextValue(i, cycle, matrix);
            if (cycle.get(i) == 0 && i != 0)
                return;
            if (i == cycle.size() - 1) {
                set.add(new ArrayList<>(cycle));
            } else {
                hamiltonianCycle(set, matrix, cycle, i + 1);
            }
        } while (cycle.get(i) != 0);
    }

    public static void nextValue(int i, ArrayList<Integer> cycle, int matrix[][]) {
        do {
            int j;
            int nextCol = (cycle.get(i) + 1) % (matrix.length);

            cycle.set(i, nextCol);

            if (nextCol == 0 && i != 0) {
                return;
            }

            if (matrix[cycle.get(i - 1)][cycle.get(i)] != 0) {
                for (j = 0; j < i - 1; j++) {
                    if (cycle.get(j).equals(nextCol)) {
                        cycle.remove(cycle.size()-1);
                        break;
                    }
                }

                if (j == i - 1) {
                    if (i == matrix.length - 1 || matrix[cycle.get(i)][cycle.get(matrix.length - 1)] != 0) {
                        return;
                    }
                }
            }
        } while (true);
    }
}*/
