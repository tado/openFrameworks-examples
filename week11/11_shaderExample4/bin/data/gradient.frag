// 頂点シェーダから渡された値
varying vec4 position;

// アプリから渡された値(経過時間)
uniform float time;

void main() {

	// 経過時間でノイズを生成
	float val = noise1(vec4(position.x/5.0, 
													position.y/5.0, 
													position.z/5.0, 
													time*4.0))+0.5;

	// 計算した結果を、アプリに反映
	gl_FragColor = vec4 (val, val, val, 1);	
}
