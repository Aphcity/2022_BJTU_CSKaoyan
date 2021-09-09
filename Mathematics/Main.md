# 高等数学

[TOC]

## 数列

$$
\sum _ { k = 1 } ^ { n } k ^ { 2 } = 1 ^ { 2 } + 2 ^ { 2 } + 3 ^ { 2 } + \cdots + n ^ { 2 } = \frac { n ( n + 1 ) ( 2 n + 1 ) } { 6 }
$$

## 三角函数

$$
\sec \alpha = \frac { 1 } { \cos \alpha }
$$

$$
1 + \tan ^ { 2 } \alpha = \sec ^ { 2 } \alpha
$$

## 二项式定理

$$
( a + b ) ^ { n } = \sum _ { k = 0 } ^ { n } C _ { n } ^ { k } a ^ { n - k } b ^ { k }
$$

## 常用不等式

$$
\begin{aligned}
    | a + b | &\leq | a | + | b |
    \\[1ex]
    | a - b | &\geq \big\lvert \vert a \vert - \vert b \vert \big\lvert
    \\[1ex]
    \sqrt { a b } \leq &\frac { a + b } { 2 } \leq \sqrt { \frac { a ^ { 2 } + b ^ { 2 } } { 2 } }
    \\[1ex]
    e ^ { x } &\geq x + 1
    \\[1ex]
    \ln x &\leq x - 1
    \\[1ex]
    \frac { 1 } { 1 + x } \leq &\ln ( 1 + \frac { 1 } { x } ) \lt \frac { 1 } { x } \space\space\ ( x \gt 0 )
\end{aligned}
$$

## Taylor 公式

$$
\begin{aligned}

\sin x &=\sum_{n=0}^{\infty}(-1)^{n} \frac{x^{2 n+1}}{(2 n+1) !} \\[1ex]
&=x-\frac{x^{3}}{3 !}+\frac{x^{5}}{5 !}-\frac{x^{7}}{7 !}+\cdots+(-1)^{n} \frac{x^{2 n+1}}{(2 n+1) !}+\cdots,-\infty<x<+\infty \text { . }

\\[1ex]

\cos x &=\sum_{n=0}^{\infty}(-1)^{n} \frac{x^{2 n}}{(2 n) !} \\[1ex]
&=1-\frac{x^{2}}{2 !}+\frac{x^{4}}{4 !}-\frac{x^{6}}{6 !}+\cdots+(-1)^{n} \frac{x^{2 n}}{(2 n) !}+\cdots,-\infty<x<+\infty \text { . }

\\[1ex]

\ln (1+x)&=\sum_{n=1}^{\infty}(-1)^{n-1} \frac{x^{n}}{n}\\[1ex]
&=x-\frac{x^{2}}{2}+\frac{x^{3}}{3}-\frac{x^{4}}{4}+\cdots+(-1)^{n-1} \frac{x^{n}}{n}+\cdots,-1<x \leqslant 1 \text { . }

\\[1ex]

\mathrm{e}^{x}&=\sum_{n=0}^{\infty} \frac{x^{n}}{n !}\\[1ex]
&=1+x+\frac{x^{2}}{2 !}+\cdots+\frac{x^{n}}{n !}+\cdots,-\infty<x<+\infty \text { . }

\\[1ex]

a^{x}&=\sum_{n=0}^{\infty} \frac{(x\ln a)^{n}}{n !}\\[1ex]
&=1+(x\ln a)+\frac{(x\ln a)^{2}}{2 !}+\cdots+\frac{(x\ln a)^{n}}{n !}+\cdots,-\infty<x<+\infty \text { . }

\\[1ex]

\frac{1}{1+x}&=\sum_{n=0}^{\infty}(-1)^{n} x^{n}\\[1ex]
&=1-x+x^{2}-x^{3}+\cdots+(-1)^{n} x^{n}+\cdots,-1<x<1 \text { . }

\\[1ex]

\frac{1}{1-x}&=\sum_{n=0}^{\infty} x^{n}\\[1ex]
&=1+x+x^{2}+\cdots+x^{n}+\cdots,-1<x<1 \text { . }

\\[1ex]

(1+x)^{\sigma}&=1+\alpha x+\frac{\alpha(\alpha-1)}{2 !} x^{2}+\cdots+\frac{\alpha(\alpha-1) \cdots(\alpha-n+1)}{n !} x^{n}+\cdots,
&\left\{
    \begin{array}{ll}
    x \in(-1,1) & \text { 当 } \alpha \leqslant-1 \text { , } \\[1ex]
    x \in(-1,1] & \text { 当 }-1<\alpha<0 \text { , } \\[1ex]
    x \in[-1,1] & \text { 当 } \alpha>0 \text { . }
    \end{array}
    \right.

\end{aligned}
$$

## 常用导数

$$
\begin{aligned}

(\tan x)^{\prime}&=\sec ^{2} x
\\[1ex]
(\cot x)^{\prime}&=-\csc ^{2} x
\\[1ex]
(\sec x)^{\prime}&=\sec x \tan x
\\[1ex]
(\csc x)^{\prime}&=-\csc x \cot x
\end{aligned}
$$

$$
\begin{aligned}
(\arcsin x)^{\prime}&=\frac{1}{\sqrt{1-x^{2}}}
\\[1ex]
(\arccos x)^{\prime}&=-\frac{1}{\sqrt{1-x^{2}}}
\end{aligned}
$$

$$
\begin{aligned}
(\arctan x)^{\prime}&=\frac{1}{1+x^{2}}
\\[1ex]
(\operatorname{arccot} x)^{\prime}&=-\frac{1}{1+x^{2}}
\end{aligned}
$$

$$
\begin{aligned}
\left[\ln \left(x+\sqrt{x^{2}+1}\right)\right]^{\prime}&=\frac{1}{\sqrt{x^{2}+1}}
\\[1ex]
\quad\left[\ln \left(x+\sqrt{x^{2}-1}\right)\right]^{\prime}&=\frac{1}{\sqrt{x^{2}-1}}
\end{aligned}
$$

## 反函数的导数

$$
y*{x}^{\prime}
=\frac{\mathrm{d} y}{\mathrm{~d} x}
=\frac{1}{\frac{\mathrm{d} x}{\mathrm{~d} y}}
=\frac{1}{x*{y}^{\prime}}
$$

$$
y*{x x}^{\prime \prime}
=\frac{\mathrm{d}^{2} y}{\mathrm{~d} x^{2}}
=\frac{\mathrm{d}\left(\frac{\mathrm{d} y}{\mathrm{~d} x}\right)}{\mathrm{d} x}
=\frac{\mathrm{d}\left(\frac{1}{x*{y}^{\prime}}\right)}{\mathrm{d} y} \cdot \frac{\mathrm{d} y}{\mathrm{~d} x}
=\frac{\mathrm{d}\left(\frac{1}{x*{y}^{\prime}}\right)}{\mathrm{d} y} \cdot \frac{1}{x*{y}^{\prime}}
=\frac{-x*{y y}^{\prime \prime}}{\left(x*{y}^{\prime}\right)^{3}}
$$

## 变限积分求导

$$
\begin{aligned}

    F^{\prime}(x)
        &=\frac{\mathrm{d}}{\mathrm{d} x}\left[\int_{\varphi_{1}(x)}^{\varphi_{2}(x)} f(t) \mathrm{d} t\right]
        \\[2ex]
        &=f\left[\varphi_{2}(x)\right] \varphi*{2}^{\prime}(x)-f\left[\varphi*{1}(x)\right] \varphi\_{1}^{\prime}(x)

\end{aligned}
$$

## N 阶导数公式

$$
\begin{aligned}
    \left(\mathrm{e}^{x}\right)^{(n)}&=\mathrm{e}^{x}
    \\[1ex]
    \left(a^{x}\right)^{(n)}&=a^{x}(\ln a)^{n}(a>0, a \neq 1)
    \\[1ex]
    (\sin k x)^{(n)}&=k^{n} \sin \left(k x+n \cdot \frac{\pi}{2}\right)
    \\[1ex]
    (\cos k x)^{(n)}&=k^{n} \cos \left(k x+n \cdot \frac{\pi}{2}\right)
    \\[1ex]
    (\ln x)^{(n)}&=(-1)^{n-1} \frac{(n-1) !}{x^{n}}(x>0)
    \\[1ex]
    [\ln (1+x)]^{(n)}&=(-1)^{n-1} \frac{(n-1) !}{(1+x)^{n}}(x>-1)
    \\[1ex]
    \left[\left(x+x_{0}\right)^{m}\right]^{(n)}&=m(m-1)(m-2) \cdots(m-n+1)\left(x+x_{0}\right)^{m-n}
    \\[1ex]
    \left(\frac{1}{x+a}\right)^{(n)}&=\frac{(-1)^{n} n !}{(x+a)^{n+1}}

\end{aligned}
$$

## 无穷小比阶

$$
\begin{aligned}

    \arcsin a x \sim \sin a x &\sim a x
    \\[1ex]
    \arctan a x \sim \tan a x &\sim a x
    \\[1ex]
    \ln (1 + x) &\sim x
    \\[1ex]
    \sqrt[b]{1 + a x}-1 &\sim \frac{a}{b} x
    \\[1ex]
    (1+a x)^{b}-1 &\sim a b x
    \\[1ex]
    \sqrt{1+x}-\sqrt{1-x} &\sim x
    \\[1ex]
    1-\cos x &\sim \frac{x^{2}}{2}
    \\[1ex]
    x-\ln (1+x) &\sim \frac{x^{2}}{2}
    \\[1ex]
    \tan x-\sin x &\sim \frac{x^{3}}{2}
    \\[1ex]
    \tan x-x &\sim \frac{x^{3}}{3}
    \\[1ex]
    x-\arctan x &\sim \frac{x^{3}}{3}
    \\[1ex]
    x-\sin x &\sim \frac{x^{3}}{6}
    \\[1ex]
    \arcsin x-x &\sim \frac{x^{3}}{6}

\end{aligned}
$$
