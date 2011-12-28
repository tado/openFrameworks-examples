void main (void)
{
	// 最終的に出力する色を、VertexShaderで設定された色から読込み
	gl_FragColor = gl_Color;
}