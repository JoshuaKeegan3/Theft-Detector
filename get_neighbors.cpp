
#include <iostream>

using namespace std;

int getNeighbors(bool *l ,int i,int j, int dist[4],int height, int width){
   // I want all nearing neighbors
   // To do this I will make a square
   // I need to know the square size
   // I will keep expanding until there are no new trues
   int total_true_neighbors=0;
   int min_x=0;
   int min_y=0;
   int max_x=0;
   int max_y=0;

   // get heighest and lowest x values
   // these are i+- dist from the centre
   if (i-dist[0] > 0){
	   dist[0] +=1;
	   min_x = i-dist[0];
   }else{
	   min_x = i-dist[0];
   }
   if (i+dist[1] < width){
	   dist[1] +=1;
	   max_x = i+dist[1];
   }else{
	   max_x = i+dist[1];
   }
   
   // get heighest and lowest y values
   // these are j+- dist from the centre
   if (j-dist[2] > 0){
	   dist[2] +=1;
	   min_y = j-dist[2];
   }else{
	   min_y = j-dist[2];
   }
   if (j+dist[3] < width){
	   dist[3] +=1;
	   max_y = j+dist[3];
   }else{
	   max_y = j+dist[3];
   }
   
   // lowest y with lowest x column by increasing y
   // lowest y with lowest x row by increasing x
  for (int y=min_y;y<max_y;y++){
	 if (l[y*width+min_x]){
		total_true_neighbors +=1;
		l[y*width+min_x]= false;
		}
	}
  for (int x=min_x;x<max_x;x++){
	 if (l[min_y*width+x]){
		total_true_neighbors +=1;
		l[min_y*width+x]= false;
		}
	}
   // highest y with highest x column by decreasing y
   // highest y with highest x row by decreasing x
  for (int y=max_y;y>min_y-1;y--){
	 if (l[y*width+max_x]){
		total_true_neighbors +=1;
		l[y*width+max_x]= false;
		}
	}
  for (int x=max_x;x>min_x-1;x--){
	 if (l[max_y*width+x]){
		total_true_neighbors +=1;
		l[max_y*width+x]= false;
		}
	}
         
   // if there is a match expand the search by returning getNeighbors(i,j, dist+1)
   // if not then return the number of neighbors
   if (total_true_neighbors>0){
      return total_true_neighbors+getNeighbors(l,i,j, dist,width,height);
  }
   else{
      return total_true_neighbors;
  }
}



      
