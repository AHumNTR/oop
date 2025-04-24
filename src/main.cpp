#include <cstdlib>
import std;

class matrix{
	public:
	float **data;
	int rows,cols;
	matrix(int RowCount,int ColumCount){
		data= new float*[RowCount];
		for (int i =0;i<RowCount;i++) {
			data[i]= new float[ColumCount];
			for(int j=0;j<ColumCount;j++){
				data[i][j]=0;
			}
		}
		rows=RowCount;
		cols=ColumCount;
	}
	matrix operator+(matrix op){
		if(op.cols==cols and op.rows==rows){
			for (int i =0;i<rows;i++) {
				for(int j=0;j<cols;j++){
					op.data[i][j]+=data[i][j];
				}
			}
		}
		return op;
	}
	matrix operator*(matrix op){

			matrix result{rows,op.cols};
		if(cols==op.rows){

			for (int i =0;i<rows;i++) {
				for(int j=0;j<op.cols;j++){
					for(int k =0;k<cols;k++) result.data[i][j]+=data[i][k]* op.data[k][j];
				}
			}
		}
		return result;
	}
	float* operator[](int i){
		return data[i];
	}
	void print(){
	
		for (int i=0;i<rows;i++) {
			for(int j=0; j<cols;j++){
				std::print("{} ",data[i][j]);
			}
		std::println("");

		}
	}
};
class Activation{

	std::string type;
	public:
	
	bool bType;
	Activation(std::string Type){
		type=Type;
		if(type=="relu")bType=false;
		else bType=true;
	}
	float relu(float input){
		if(input<0)return 0;
		else return input;
	}

	float sigmoid(float input){
		return 1/(1+std::exp(-1*input));
	}
	float operator()(float input)
	{
		if(bType) return sigmoid(input);
		else return relu(input);
	}	
};
class layer{
	matrix weights, biases;
	Activation& act;
	public:
	layer(int inputSize,int outputSize,Activation& activation): weights(inputSize, outputSize),biases(1, outputSize),act(activation){
	}
	matrix forward(matrix input){
		matrix m(input*weights+biases);
		for(int i =0; i<m.rows;i++){
			for(int j=0;j<m.cols;j++){
				m[i][j]=act(m[i][j]);
			}
		}
		return m; 
	}
	void initializeWeights(){

		for(int i =0; i<weights.rows;i++){
			for(int j=0;j<weights.cols;j++){
				weights[i][j]=((float)std::rand())/RAND_MAX;
			}
		}
	}
};

class Network{
	layer** layers;
	int layerCount,maxLayerCount;
	public:
	Network(int maxLayers)
	{
		maxLayerCount=maxLayers;
		layerCount=0;
		layers= new layer*[maxLayers];
	}
	bool addLayer(layer* newLayer){
		if(layerCount<maxLayerCount-1){
		layers[layerCount]= newLayer;
		layerCount++;
		return true;
		}
		else return false;
	}
	int getLayerCount(){return layerCount;};
	matrix forward(matrix inputMatrix){
		for(int i=0;i<layerCount;i++){
			inputMatrix= layers[i]->forward(inputMatrix);
		}
		return inputMatrix;
	}
};
int main(){
	// Create activation functions
 Activation relu { " relu " };
 Activation sigmoid { " sigmoid " };

 // Create a simple neural network for XOR problem
 // Input layer : 2 neurons
 // Hidden layer : 3 neurons with ReLU activation
 // Output layer : 1 neuron with Sigmoid activation

 // Create layers
 layer hiddenLayer {2 , 3 , relu };
 layer outputLayer {3 , 1 , sigmoid };

 // Create network with a maximum of 2 layers and add layers
 Network network {2};
 network . addLayer (& hiddenLayer ) ;
 network . addLayer (& outputLayer ) ;

 std :: cout << " Neural Network with " << network . getLayerCount () << " layers created . " << std :: endl ;

 // Create input data for XOR problem
 // [0 ,0] , [0 ,1] , [1 ,0] , [1 ,1]
 matrix input {4 , 2};
 input [0][0] = 0.0f ; input [0][1] = 0.0f ;
 input [1][0] = 0.0f ; input [1][1] = 1.0f ;
 input [2][0] = 1.0f ; input [2][1] = 0.0f ;
 input [3][0] = 1.0f ; input [3][1] = 1.0f ;

 std :: cout << " Input data : " << std :: endl ;
 input.print () ;
 // Forward pass through the network
 matrix output = network.forward ( input ) ;

 std::cout << " Network output : " << std :: endl ;
 output.print();


 std :: cout << " Note : Since weights are randomly initialized , the output won 't match XOR truth table yet . " << std :: endl ;
 std :: cout << " Training would be needed to adjust weights for correct predictions . " << std :: endl ;

 return 0;
 }

