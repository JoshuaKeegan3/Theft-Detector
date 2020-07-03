#include "video_proc.hpp"
#include "get_neighbors.cpp"

int main(){

    int nFrames = 20;
    int pmaxY;
    int pmaxX;
    int pminY;
    int pminX;
    for ( int iFrame = 0; iFrame < nFrames ; iFrame++){
		// produce file name of "X.ppm" type where X goes from 0 to number of images
		std::string fileName;
		std::ostringstream stringStream;
        //stringStream <<"Images/Core/"<<iFrame<<".ppm";
        //stringStream <<"Images/Completion/theft/"<<iFrame<<".ppm";
        //stringStream <<"Images/Completion/falsealarm/"<<iFrame<<".ppm";
        stringStream <<"Images/Challenge/"<<iFrame<<".ppm";
        fileName = stringStream.str();
		//std::cout<<" File::"<<fileName<<std::endl;
		// open image file
		OpenPPMFile(fileName);
		
	
        int totred = 0;
        bool there=false;
        //int totint = 0;
        //float redness = 0;
        Pixel curPix;
        int totblue=0;
        int totgreen=0;
        int maxY=image.height;
        int minY=0;
        int maxX=image.width;
        int minX=0;
        
        
        for ( int row =0 ; row < image.height ; row++)
	    {	
		  for ( int column = 0; column < image.width ; column++)
		  {
			  curPix = get_pixel(row,column);
			  totred += curPix.red;
			  totblue += curPix.blue;
			  totgreen += curPix.green;
			  
			  if(curPix.red>2*curPix.blue && curPix.red>2*curPix.green){
				  there=true;
				  maxY=max(maxY,row);
				  maxX=max(maxX,column);
				  minY=min(maxY,row);
				  minX=min(maxX,column);
			  }
		   }
	    }
		if (there){
			std::cout<<"There"<<endl;
		}
		else{
			std::cout<<"Gone"<<endl;
		}
		if(iFrame>0){
			if(pmaxY!=maxY||
			pmaxX!=maxX||
			pminY!=minY||
			pminX!=minX){
				std::cout<<"Movement"<<endl;
			}
			else{
				std::cout<<"no Movement"<<endl;
			}
		}
		pmaxY=maxY;
	    pmaxX=maxX;
	    pminY=minY;
	    pminX=minX;

	}
	
	return 0; 
}
