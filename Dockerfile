FROM archlinux

RUN pacman -Sy --noconfirm git neovim make gcc zsh curl

RUN sh -c "$(curl -fsSL https://raw.github.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

COPY . minishell

ENTRYPOINT [ "zsh" ]
