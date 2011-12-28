void main(void)
{
	// アプリケーションから取得した座標をGLSL用に変換
	gl_Position = ftransform();
	
	// 法線の方向からRGBの値を決定
	gl_FrontColor.rgb = 0.5 * gl_Normal.xyz + 0.5;

	// アルファ値を1.0(不透明)に
	gl_FrontColor.a = 1.0;
}