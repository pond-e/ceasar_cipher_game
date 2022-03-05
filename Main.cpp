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


void Main()
{
	// 背景の色を設定 | Set background color
	Scene::SetBackground(ColorF{ 0.8, 0.9, 1.0 });

	const Font dialFont{ 18, Typeface::CJK_Regular_JP, FontStyle::Bold };

	// Ceasar cipher problem
	Print << U"例：";
	Print << U"問題：いきすさえそあふらえさた！";
	Print << U"答え：あかしこうせんへようこそ！";

	// ストップウォッチ（作成と同時に計測開始）
	Stopwatch stopwatch{ StartImmediately::Yes };

	while (System::Update())
	{
		constexpr size_t PasswordDigits = 6;
		Array<uint32> inputs(PasswordDigits);

		// 中心座標 (400, 300), 半径 20 の円を描く
		Circle(400, 300, 60).draw(ColorF{ 1, 1, 0, 1 });

		// マウスカーソルに追随する半透明な円を描く | Draw a red transparent circle that follows the mouse cursor
		Circle{ Cursor::Pos(), 40 }.draw(ColorF{ 1, 0, 0, 0.5 });

		// もし [A] キーが押されたら | When [A] key is down
		if (KeyA.down())
		{
			// 選択肢からランダムに選ばれたメッセージをデバッグ表示 | Print a randomly selected text
			Print << Sample({ U"Hello!", U"こんにちは", U"你好", U"안녕하세요?" });
		}

		// もし左クリックされたら
		if (MouseL.down())
		{
			// ストップウォッチをリセットして再び 0 から計測
			stopwatch.restart();
		}

		// ストップウォッチの経過時間（秒）を double 型で取得 
		const double t = stopwatch.sF();

		Circle{ Scene::Center(), (t * 50) }.draw(ColorF{ 0.25 });


		const Vec2 pos{ 120 + 0 * 210, 460 };
		UpdateDial(dialFont, pos, inputs[0]);
		
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
