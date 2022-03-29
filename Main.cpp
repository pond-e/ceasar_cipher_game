# include <Siv3D.hpp> // OpenSiv3D v0.6.3

void UpdateDial(const Font& font, const Vec2& pos, uint32& value)
{
	const Circle circle{ pos, 70 };
	const Circle baseCircle = circle.movedBy(0, 8);

	if (circle.mouseOver())
	{
		Cursor::RequestStyle(CursorStyle::Hand);

		if (MouseL.down())
		{
			double angle = (Cursor::Pos() - circle.center).getAngle();

			if (angle < 0_deg)
			{
				angle += 2_pi;
			}

			const double ta = (value * 36_deg);

			if (ta < 180_deg)
			{
				if (InRange(angle, ta, ta + 180_deg))
				{
					value = (value + 1) % 10;
				}
				else
				{
					value = (value + 9) % 10;
				}
			}
			else
			{
				if (InRange(angle, ta - 180_deg, ta))
				{
					value = (value + 9) % 10;
				}
				else
				{
					value = (value + 1) % 10;
				}
			}
		}
	}

	for (auto i : step(10))
	{
		const Vec2 p0 = baseCircle.getPointByAngle(i * 36_deg);
		const Vec2 pos = baseCircle.center.lerp(p0, 1.15);
		font(i).drawAt(pos.movedBy(0, -2), ColorF{ 0.1 });
	}

	baseCircle.drawShadow(Vec2{ 0, 4 }, 12, 2);
	baseCircle.draw(ColorF{ 0.15 });
	circle.draw(ColorF{ 0.25 });
	{
		const Vec2 p0 = circle.getPointByAngle(value * 36_deg);
		const Vec2 p1 = circle.center.lerp(p0, 0.4);
		Line{ p0, p1 }.draw(LineStyle::Uncapped, 5, ColorF{ 0.6 });
	}
}

String ceasar(int slide, String word) {
	int i, j, count = 0;
	const String boin = U"aiueo";
	while (word[count]) {
		count++;
	}
	for (i = 0; i < count; i++) {
		if (word[i] == 'a' || word[i] == 'i' || word[i] == 'u' || word[i] == 'e' || word[i] == 'o') {
			for (j = 0; j < 5; j++) {
				if (word[i] == boin[j]) {
					word[i] = boin[(j + slide) % 5];
					break;
				}
			}
		}
	}
	return word;
}

String table_romaji_to_kana(String romaji) {
	String kana;
	if (romaji == U"a") {
		kana = U"あ";
	}
	else if (romaji == U"i") {
		kana = U"い";
	}
	else if (romaji == U"u") {
		kana = U"う";
	}
	else if (romaji == U"e") {
		kana = U"え";
	}
	else if (romaji == U"o") {
		kana = U"お";
	}
	else if (romaji == U"ka") {
		kana = U"か";
	}
	else if (romaji == U"ki") {
		kana = U"き";
	}
	else if (romaji == U"ku") {
		kana = U"く";
	}
	else if (romaji == U"ke") {
		kana = U"け";
	}
	else if (romaji == U"ko") {
		kana = U"こ";
	}
	else if (romaji == U"sa") {
		kana = U"さ";
	}
	else if (romaji == U"si") {
		kana = U"し";
	}
	else if (romaji == U"su") {
		kana = U"す";
	}
	else if (romaji == U"se") {
		kana = U"せ";
	}
	else if (romaji == U"so") {
		kana = U"そ";
	}
	else if (romaji == U"ta") {
		kana = U"た";
	}
	else if (romaji == U"ti") {
		kana = U"ち";
	}
	else if (romaji == U"tu") {
		kana = U"つ";
	}
	else if (romaji == U"te") {
		kana = U"て";
	}
	else if (romaji == U"to") {
		kana = U"と";
	}
	else if (romaji == U"na") {
		kana = U"な";
	}
	else if (romaji == U"ni") {
		kana = U"に";
	}
	else if (romaji == U"nu") {
		kana = U"ぬ";
	}
	else if (romaji == U"ne") {
		kana = U"ね";
	}
	else if (romaji == U"no") {
		kana = U"の";
	}
	else if (romaji == U"ha") {
		kana = U"は";
	}
	else if (romaji == U"hi") {
		kana = U"ひ";
	}
	else if (romaji == U"hu") {
		kana = U"ふ";
	}
	else if (romaji == U"he") {
		kana = U"へ";
	}
	else if (romaji == U"ho") {
		kana = U"ほ";
	}
	else if (romaji == U"ma") {
		kana = U"ま";
	}
	else if (romaji == U"mi") {
		kana = U"み";
	}
	else if (romaji == U"mu") {
		kana = U"む";
	}
	else if (romaji == U"me") {
		kana = U"め";
	}
	else if (romaji == U"mo") {
		kana = U"も";
	}
	else if (romaji == U"ya") {
		kana = U"や";
	}
	else if (romaji == U"yi") {
		kana = U"い";
	}
	else if (romaji == U"yu") {
		kana = U"ゆ";
	}
	else if (romaji == U"ye") {
		kana = U"え";
	}
	else if (romaji == U"yo") {
		kana = U"よ";
	}
	else if (romaji == U"ra") {
		kana = U"ら";
	}
	else if (romaji == U"ri") {
		kana = U"り";
	}
	else if (romaji == U"ru") {
		kana = U"る";
	}
	else if (romaji == U"re") {
		kana = U"れ";
	}
	else if (romaji == U"ro") {
		kana = U"ろ";
	}
	else if (romaji == U"wa") {
		kana = U"わ";
	}
	else if (romaji == U"wi") {
		kana = U"い";
	}
	else if (romaji == U"wu") {
		kana = U"う";
	}
	else if (romaji == U"we") {
		kana = U"え";
	}
	else if (romaji == U"wo") {
		kana = U"を";
	}
	else if (romaji == U"ga") {
		kana = U"が";
	}
	else if (romaji == U"gi") {
		kana = U"ぎ";
	}
	else if (romaji == U"gu") {
		kana = U"ぐ";
	}
	else if (romaji == U"ge") {
		kana = U"げ";
	}
	else if (romaji == U"go") {
		kana = U"ご";
	}
	else if (romaji == U"za") {
		kana = U"ざ";
	}
	else if (romaji == U"zi") {
		kana = U"じ";
	}
	else if (romaji == U"zu") {
		kana = U"ず";
	}
	else if (romaji == U"ze") {
		kana = U"ぞ";
	}
	else if (romaji == U"da") {
		kana = U"だ";
	}
	else if (romaji == U"di") {
		kana = U"ぢ";
	}
	else if (romaji == U"du") {
		kana = U"づ";
	}
	else if (romaji == U"de") {
		kana = U"で";
	}
	else if (romaji == U"do") {
		kana = U"ど";
	}
	else if (romaji == U"ba") {
		kana = U"ば";
	}
	else if (romaji == U"bi") {
		kana = U"び";
	}
	else if (romaji == U"bu") {
		kana = U"ぶ";
	}
	else if (romaji == U"be") {
		kana = U"べ";
	}
	else if (romaji == U"bo") {
		kana = U"ぼ";
	}
	else if (romaji == U"pa") {
		kana = U"ぱ";
	}
	else if (romaji == U"pi") {
		kana = U"ぴ";
	}
	else if (romaji == U"pu") {
		kana = U"ぷ";
	}
	else if (romaji == U"pe") {
		kana = U"ぺ";
	}
	else if (romaji == U"po") {
		kana = U"ぽ";
	}
	else if (romaji == U"ltu") {
		kana = U"っ";
	}
	else if (romaji == U"lya") {
		kana = U"ゃ";
	}
	else if (romaji == U"lyu") {
		kana = U"ゅ";
	}
	else if (romaji == U"lyo") {
		kana = U"ょ";
	}
	else {
		kana = U"ん";
	}

	return kana;
}

String romaji_to_kana(String romaji) {
	String kana;
	String tmp;
	const int len_romaji = romaji.size();
	for (int i = 0; i < len_romaji; i++) {
		tmp << romaji[i];
		if (i != 0 && romaji[i - 1] == 'n' && romaji[i] == 'n') {
			kana += table_romaji_to_kana(tmp);
			tmp.clear();
		}
		else if (romaji[i] == ' ') {
			kana += U" ";
			tmp.clear();
		}
		else if (romaji[i] == 'a' || romaji[i] == 'i' || romaji[i] == 'u' || romaji[i] == 'e' || romaji[i] == 'o') {
			kana += table_romaji_to_kana(tmp);
			tmp.clear();
		}
	}
	return kana;
}

void Main()
{
	// 背景の色を設定 | Set background color
	Scene::SetBackground(ColorF{ 0.9, 0.59, 0.48 });

	const Font dialFont{ 18, Typeface::CJK_Regular_JP, FontStyle::Bold };

	// Ceasar cipher problem
	Print << U"暗号を解いてみよう！";
	Print << U"例↓";
	Print << U"問題：いきすさえそあふらえさた！";
	Print << U"答え：あかしこうせんへようこそ！";

	//int slide = 1;
	int i = 0;
	//Print << U"かけきつせん";
	//const String words = U"kakekitusenn";
	//const String reword = romaji_to_kana(ceasar(slide, words));
	//Print << reword;

	Print << U"";
	Print << U"ええろうな　すゃえちうむちる　きろあびに";
	String kare = U"yeerouna sulyaetiumutiru kiroabini";
	//Print << U"答え：ゆうれいの　しょうたいみたり　かれおばな";
	String rekare;

	constexpr size_t PasswordDigits = 1;
	Array<uint32> inputs(PasswordDigits); // inputsにはダイヤルの数字が入る
	
	while (System::Update())
	{

		// マウスカーソルに追随する半透明な円を描く | Draw a red transparent circle that follows the mouse cursor
		Circle{ Cursor::Pos(), 40 }.draw(ColorF{ 1, 0, 0, 0.5 });

		const Array<uint32> old = inputs;
		for (auto i : step(PasswordDigits))
		{
			const Vec2 pos{ 400, 460 };
			UpdateDial(dialFont, pos, inputs[i]);
			rekare = romaji_to_kana(ceasar(inputs[i], kare));
			dialFont(rekare).drawAt( 400, 300, Palette::Black);

		}
	}
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク | Quick Links =
//
// Siv3D リファレンス
// https://zenn.dev/reputeless/books/siv3d-documentation
//
// Siv3D Reference
// https://zenn.dev/reputeless/books/siv3d-documentation-en
//
// Siv3D コミュニティへの参加
// Slack や Twitter, BBS で気軽に質問や情報交換ができます。
// https://zenn.dev/reputeless/books/siv3d-documentation/viewer/community
//
// Siv3D User Community
// https://zenn.dev/reputeless/books/siv3d-documentation-en/viewer/community
//
// 新機能の提案やバグの報告 | Feedback
// https://github.com/Siv3D/OpenSiv3D/issues
//
