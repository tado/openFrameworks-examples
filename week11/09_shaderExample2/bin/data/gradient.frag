// 頂点シェーダから値を受けとるための変数
varying vec4 position;

// アプリケーションから値を受けとる
uniform float x;
uniform float y;
uniform float w;
uniform float h;
uniform float color;

// 色を計算
void main() {
	float pctx = (position.x - x) / w;
	float pcty = (position.y - y) / h;
	gl_FragColor = vec4 (pctx, pcty, color,1);
}
