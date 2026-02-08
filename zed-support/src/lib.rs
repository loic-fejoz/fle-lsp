use zed_extension_api::{self as zed, LanguageServerId, Result, settings::LspSettings};

struct ZedFleLspExtension {}

impl zed::Extension for ZedFleLspExtension {
    fn new() -> Self
    where
        Self: Sized,
    {
        Self {}
    }

    fn language_server_command(
        &mut self,
        language_server_id: &LanguageServerId,
        worktree: &zed::Worktree,
    ) -> Result<zed::Command> {
        let settings = LspSettings::for_worktree(language_server_id.as_ref(), worktree)?;
        if let Some(binary) = settings.binary {
            if let Some(path) = binary.path {
                return Ok(zed::Command {
                    command: path,
                    args: binary.arguments.unwrap_or_default(),
                    env: Default::default(),
                });
            }
        }

        if let Some(path) = worktree.which("fle-lsp") {
            return Ok(zed::Command {
                command: path,
                args: vec![],
                env: Default::default(),
            });
        }

        Err("fle-lsp binary not found in PATH. You can set a custom path in settings.json under lsp.fle.binary.path".to_string())
    }
}

zed::register_extension!(ZedFleLspExtension);
