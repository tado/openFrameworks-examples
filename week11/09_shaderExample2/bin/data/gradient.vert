// フラグメントシェーダへ値を渡すための変数
varying vec4 position;

void main() {
	// アプリケーションから取得した座標をGLSL用に変換
	gl_Position = ftransform();
	// 現在の頂点の情報を、フラグメントシェーダへ値を渡す
	position = gl_Vertex;
}