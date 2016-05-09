#version 330

uniform vec2 u_resolution; // 画面の解像度(width,height)

uniform float u_time; // 起動してからの経過時間(秒)

const int NUM = 20; // 波の数

uniform float freq[20]; // oFから受けとる波の配列
// uniform float freq[20] = float[](9.03064,7.94211,7.02804,4.324,7.47026,8.60781,5.54742,7.45386,8.95515,5.2697,7.82235,4.23758,6.94206,5.25526,5.15126,9.24514,7.03514,9.57763,9.20484,7.7227); // oFから受けとる波の配列

out vec4 fragColor;

void main() {

  vec3 color;

  // 波の数だけくりかえす
  for (int i = 0; i < NUM; i++) {

    //画面の解像度から、0.0~1.0に正規化する
    vec2 st = gl_FragCoord.xy / u_resolution;

    // 画面の中央をy軸の中心に
    st.y -= 0.5;

    // Sin波で濃淡をつける + 時間による変化
    st.y += sin(st.x * freq[i] + u_time) * 0.2 * sin(u_time * freq[i] * 0.1);

    // 1から引いて、乗算する
    color += vec3(1.0 - pow(abs(st.y), 0.75/float(NUM)));

    // 色を設定
    if( freq[i] == 0.0 ) {
      fragColor = vec4(1.0, 1.0, 1.0, 1.0);
    }else {
      fragColor = vec4(color.r * 0.2, color.g * 0.5, color.b * 1.0, 1.0);
    }
    // if( freq[i] == 0.0 ) {
    //   gl_FragColor = vec4(1.0, 1.0, 1.0, 1.0);
    // }else {
    //   gl_FragColor = vec4(color.r * 0.2, color.g * 0.5, color.b * 1.0, 1.0);
    // }
  }

}
