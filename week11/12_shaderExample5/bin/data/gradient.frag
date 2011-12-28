// 頂点シェーダから渡された値
varying vec4 position;

// アプリから渡された値(経過時間)
uniform float time;

void main() {

	// RGB別々にSin関数で濃度の波(縞模様)を生成
	float val_r = sin(position.x + time * 400.0) * 0.5 + 0.5;
	float val_g = sin(position.y + time * 400.0) * 0.5 + 0.5;
	float val_b = sin(position.z + time * 400.0) * 0.5 + 0.5;
	
	// 計算した結果を、アプリに反映
	gl_FragColor = vec4 (val_r, val_g, val_b, 1);	
}
